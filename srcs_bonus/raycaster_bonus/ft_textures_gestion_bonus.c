/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_gestion_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:34:22 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/13 18:34:43 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header_bonus.h"

static int	ft_make_color(mlx_texture_t *texture, double tmp, double dist_y)
{
	int	index;
	int	color[3];
	int	x;
	int	y;

	x = texture->width * tmp;
	y = (texture->height) * (dist_y);
	index = (x + (y * (texture->width))) << 2;
	color[0] = texture->pixels[index];
	color[1] = texture->pixels[index + 1];
	color[2] = texture->pixels[index + 2];
	return ((color[0] << 24) + (color[1] << 16) + (color[2] << 8) + 255);
}

static void	ft_which_face_2(double *prog, mlx_texture_t **img,
	t_gpt *center, const int i)
{
	if (center->fov[i].dir == TOP)
	{
		*prog = 1.0 - ((center->fov[i].x / (double)center->size) - \
				(int)(center->fov[i].x / (double)center->size));
		*img = center->textures_tab.north;
	}
	else if (center->fov[i].dir == BOTTOM)
	{
		*prog = (center->fov[i].x / (double)center->size)
			- (int)(center->fov[i].x / (double)center->size);
		*img = center->textures_tab.south;
	}
	else
		*prog = -1;
}

static void	ft_which_face(double *prog, mlx_texture_t **img,
	t_gpt *center, const int i)
{
	if (center->fov[i].dir == LEFT)
	{
		*prog = (center->fov[i].y / (double)center->size)
			- (int)(center->fov[i].y / (double)center->size);
		*img = center->textures_tab.west;
	}
	else if (center->fov[i].dir == RIGHT)
	{
		*prog = 1.0 - ((center->fov[i].y / (double)center->size) - \
				(int)(center->fov[i].y / (double)center->size));
		*img = center->textures_tab.east;
	}
	else
		ft_which_face_2(prog, img, center, i);
}

int	ft_adapt_textures(t_gpt *center, int *xy, double dist_y)
{
	const int				i = xy[0];
	static int				old_i = 99;
	static double			prog = 0;
	static mlx_texture_t	*img = NULL;

	if (old_i != i)
	{
		old_i = i;
		ft_which_face(&prog, &img, center, i);
	}
	if (prog < 0)
		return (0x7777FFFF);
	return (ft_make_color(img, prog, dist_y));
}
