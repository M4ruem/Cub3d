/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:30:06 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/17 18:13:13 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

void    ft_dda(t_gpt *center, int *p1, int *p2, int color)
{
	float    steps;
	float    x;
	float    y;
	int        i;
	double	dxy[2];

	steps = abs(p2[0] - p1[0]);
	if (steps < abs(p2[1] - p1[1]))
		steps = abs(p2[1] - p1[1]);
	dxy[0] = (p2[0] - p1[0]) / steps;
	dxy[1] = (p2[1] - p1[1]) / steps;
	x = (p1[0] + 0.5f);
	y = (p1[1] + 0.5f);
	i = 1;
	while (i <= steps + 1)
	{
		mlx_put_pixel(center->player.pos, (int)x, (int)y, color);
		x += dxy[0];
		y += dxy[1];
		i++;
	}
}


void	ft_set_color_player(t_gpt *center)
{
	int		x;
	int		y;
	int tmp[2];
	int end[2];

	x = -1;
	while (++x < (int)(center->player.pos->width / ft_max_map_side(center) / 3))
	{
		y = -1;
		while (++y < (int)(center->player.pos->height \
			/ ft_max_map_side(center) / 3))
			mlx_put_pixel(center->player.pos, x + 100, y + 100, 0xFF00FFFF);
	}
	tmp[0] = 103;
	tmp[1] = 103;
	end[0] = tmp[0] + (cosf(center->a) * 20);
	end[1] = tmp[1]+ (sinf(center->a) * 20);
	ft_dda(center, tmp, end, 0xFF00FFFF);
}

void	draw_pixel_around(mlx_image_t *img, int x, int y, int color)
{
	int	max_x;
	int	max_y;

	max_x = x + 25;
	max_y = y + 25;
	while (x < max_x)
	{
		y = max_y - 25;
		while (y < max_y)
		{
			if (y == max_y - 1 || x == max_x - 25)
				mlx_put_pixel(img, x, y, 0x888888FF);
			else
				mlx_put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_set_color_minimap(t_gpt *center)
{
	int		x;
	int		y;
	int		i;
	int		j;

	i = 0;
	y = 0;
	while (y < (int)center->minimap->width && center->data->map[i])
	{
		j = 0;
		x = 0;
		while (x < (int)center->minimap->height && center->data->map[i][j])
		{
			if (center->data->map[i][j] == '1')
				draw_pixel_around(center->minimap, x, y, 0xFFFFFFFF);
			else
				draw_pixel_around(center->minimap, x, y, 0x000000FF);
			x += 25; /// 8 / ft_max_map_side(center)));
			j++;
		}
		y += 25; // / 8 / ft_max_map_side(center)));
		i++;
	}
}
