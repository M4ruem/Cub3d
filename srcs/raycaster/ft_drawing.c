/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:30:06 by cormiere          #+#    #+#             */
/*   Updated: 2023/09/05 17:22:09 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

int	ft_out_of_range(int x, int y, mlx_image_t *img)
{
	if (x < 0 || y < 0 || (uint32_t)x >= img->width || (uint32_t)y >= img->height)
		return (1);
	return (0);
}

void	ft_dda(t_gpt *center, int *p1, int *p2, int color)
{
	float	steps;
	float	x;
	float	y;
	int		i;
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
		if (ft_out_of_range(x, y, center->minimap))
			break ;
		mlx_put_pixel(center->minimap, (int)x, (int)y, color);
		x += dxy[0];
		y += dxy[1];
		i++;
	}
}

void	ft_set_color_player(t_gpt *center)
{
	int	x;
	int	y;
	static int	tmp[2] = {100, 100};
	int	end[2];

	x = -1;
	while (++x < PLAYER_SIZE)
	{
		y = -1;
		while (++y < PLAYER_SIZE)
		{
			mlx_put_pixel(center->minimap, 100 + x - HALF_PLAYER_SIZE, \
				100 + y - HALF_PLAYER_SIZE, 0xFF00FFFF);
		}
	}
	ft_trace_rays(center, 0);
	end[0] = (double)tmp[0] + (cosf(center->player.angle) * 15.0);
	end[1] = (double)tmp[1] + (sinf(center->player.angle) * 15.0);
	ft_dda(center, tmp, end, 0xFF00FFFF);
}

static void	draw_pixel_around(t_gpt *center, int x, int y, int color)
{
	int	max_x;
	int	max_y;

	max_x = x + center->size;
	max_y = y + center->size;
	while (x < max_x)
	{
		y = max_y - (center->size + 1);
		while (++y < max_y)
		{
			if (y == max_y - 1 || x == max_x - center->size)
			{
				if (ft_still_inside(center, x, y))
					mlx_put_pixel(center->minimap, (double)x + 100.0 - center->player.x, \
						(double)y + 100.0 - center->player.y, 0x888888FF);
			}
			else
			{
				if (ft_still_inside(center, x, y))
					mlx_put_pixel(center->minimap, (double)x + 100.0 - center->player.x, \
						(double)y + 100.0 - center->player.y, color);
			}
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

	i = -1;
	y = 0;
	while (center->data->map[++i])
	{
		j = -1;
		x = 0;
		while (center->data->map[i][++j])
		{
			if (center->data->map[i][j] == '1')
				draw_pixel_around(center, x, y, 0xFFFFFFFF);
			else if (center->data->map[i][j] == '0'
				|| center->data->map[i][j] == 'N' \
				|| center->data->map[i][j] == 'E' \
				|| center->data->map[i][j] == 'S'\
				|| center->data->map[i][j] == 'W') \
				draw_pixel_around(center, x, y, 0x000000FF);
			x += center->size;
		}
		y += center->size;
	}
	ft_set_color_player(center);
}
