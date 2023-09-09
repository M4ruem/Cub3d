/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_gestion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:53:39 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/07 16:59:18 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

int	ft_adapt_color_floor(t_gpt *center)
{
	int	color;

	color = (center->data->floor_rgb[0] * (65536 * 256)) + \
		(center->data->floor_rgb[1] * 65536) \
		+ (center->data->floor_rgb[2] * 256) + 255;
	return (color);
}

int	ft_adapt_color_ceiling(t_gpt *center)
{
	int	color;

	color = (center->data->ceiling_rgb[0] * (65536 * 256)) + \
		(center->data->ceiling_rgb[1] * 65536) \
		+ (center->data->ceiling_rgb[2] * 256) + 255;
	return (color);
}

void	ft_set_draw_around_color(t_gpt *center, char c, int x, int y)
{
	if (c == '1')
		draw_pixel_around(center, x + center->size, \
		y + center->size, 0xFFFFFFFF);
	else
		draw_pixel_around(center, x + center->size, \
		y + center->size, 0x000000FF);
}
