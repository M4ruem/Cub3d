/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coloring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:30:06 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/14 14:30:28 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

void	ft_set_color_player(void *arg)
{
	t_gpt	*center;
	int		x;
	int		y;

	center = (t_gpt *)arg;
	x = 0;
	while (x < (int)center->player->width)
	{
		y = 0;
		while (y < (int)center->player->height)
		{
			mlx_put_pixel(center->player, x, y, 0xFF00FFFF);
			y++;
		}
		x++;
	}
}

void	draw_pixel_around(mlx_image_t *img, int x, int y)
{
	int	max_x;
	int	max_y;

	max_x = x + 50;
	max_y = y + 50;
	while (x < max_x)
	{
		y = max_y - 50;
		while (y < max_y)
		{
			if (y == max_y - 1 || x == max_x - 50)
				mlx_put_pixel(img, x, y, 0x000000FF);
			else
				mlx_put_pixel(img, x, y, 0xFFFFFFFF);
			y++;
		}
		x++;
	}
}

void	ft_set_color_minimap(void *arg)
{
	t_gpt	*center;
	int		x;
	int		y;

	center = (t_gpt *)arg;
	x = 0;
	while (x < (int)center->minimap->width)
	{
		y = 0;
		while (y < (int)center->minimap->height)
		{
			draw_pixel_around(center->minimap, x, y);
			y += 50;
		}
		x += 50;
	}
}
