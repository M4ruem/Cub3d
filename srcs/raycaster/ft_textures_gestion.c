/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_gestion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:34:22 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/04 16:59:34 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

static int	ft_make_color(mlx_texture_t *texture, double tmp, double dist_y)
{
	int index;
	int	color[3];
	int	x;
	int	y;

	x = texture->width * tmp;
	y = (texture->height) * (dist_y);
	index = (x + (y * (texture->width))) * 4;
	color[0] = texture->pixels[index];
	color[1] = texture->pixels[index + 1];
	color[2] = texture->pixels[index + 2];
	return ((color[0] << 24) + (color[1] << 16) + (color[2] << 8) + 255);
}

static void		ft_which_face(double *prog, mlx_texture_t **img,
	t_gpt *center, const int i)
{
	if (cosf(center->fov[i].angle) > 0 && center->fov[i].dir == VERTICAL)
	{
		*prog = (center->fov[i].y /  25.0) - (int)(center->fov[i].y / 25.0);
		*img = center->textures_tab.west;
	}
	else if (cosf(center->fov[i].angle) < 0 && center->fov[i].dir == VERTICAL)
	{
		*prog = 1.0 - ((center->fov[i].y / 25.0) - \
				(int)(center->fov[i].y / 25.0));
		*img = center->textures_tab.east;
	}
	else if (sinf(center->fov[i].angle) > 0 && center->fov[i].dir == HORIZONTAL)
	{
		*prog = 1.0 - ((center->fov[i].x / 25.0) - \
				(int)(center->fov[i].x / 25.0));
		*img = center->textures_tab.north;
	}
	else if (sinf(center->fov[i].angle) < 0 && center->fov[i].dir == HORIZONTAL)
	{
		*prog = (center->fov[i].x / 25.0) - (int)(center->fov[i].x / 25.0);
		*img = center->textures_tab.south;
	}
	else
		*prog = -1;
}

int	ft_adapt_textures(t_gpt *center, int *xy, double dist_y)
{
	const int	i = xy[0];
	static	int	old_i = 99;
	static	double	prog = 0;
	static mlx_texture_t *img = NULL;

	if (old_i != i)
	{
		old_i = i;
		ft_which_face(&prog, &img, center, i);
	}
	if (prog < 0)
		return (0x7777FFFF);
	return (ft_make_color(img, prog, dist_y));
}
