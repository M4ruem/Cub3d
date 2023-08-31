/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_gestion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:34:22 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/31 15:59:07 by jdelsol-         ###   ########.fr       */
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

int	ft_adapt_textures(t_gpt *center, int *xy, double dist_y)
{
	const int	i = xy[0];
	
	if (cosf(center->fov[i].angle) > 0 \
		&& center->fov[i].dir == VERTICAL)
		return (ft_make_color(center->textures_tab.east, (center->fov[i].y / \
			25.0) - (int)(center->fov[i].y / 25.0), dist_y));
	else if (cosf(center->fov[i].angle) < 0 \
		&& center->fov[i].dir == VERTICAL)
		return (ft_make_color(center->textures_tab.west, (center->fov[i].y / \
			25.0) - (int)(center->fov[i].y / 25.0), dist_y));
	else if (sinf(center->fov[i].angle) > 0 \
		&& center->fov[i].dir == HORIZONTAL)
		return (ft_make_color(center->textures_tab.south, (center->fov[i].x / \
			25.0) - (int)(center->fov[i].x / 25.0), dist_y));
	else if (sinf(center->fov[i].angle) < 0 \
		&& center->fov[i].dir == HORIZONTAL)
		return (ft_make_color(center->textures_tab.north, (center->fov[i].x / \
			25.0) - (int)(center->fov[i].x / 25.0), dist_y));
	else
		return (0x7777FFFF);
}