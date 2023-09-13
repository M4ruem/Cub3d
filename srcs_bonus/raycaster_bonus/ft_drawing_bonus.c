/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:30:06 by cormiere          #+#    #+#             */
/*   Updated: 2023/09/13 18:34:20 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header_bonus.h"

int	ft_out_of_range(int x, int y, mlx_image_t *img)
{
	if (x < 0 || y < 0 || (uint32_t)x >= img->width
		|| (uint32_t)y >= img->height)
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
	int			x;
	int			y;
	static int	tmp[2] = {100, 100};
	int			end[2];

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

void	draw_pixel_around(t_gpt *center, int x, int y, int color)
{
	const int	max_xy[2] = {x + center->size, y + center->size};

	x--;
	while (++x < max_xy[0])
	{
		y = max_xy[1] - (center->size + 1);
		while (++y < max_xy[1])
		{
			if (x == max_xy[0] - center->size \
				|| (y == max_xy[1] - center->size))
			{
				if (ft_still_inside(center, x, y))
					mlx_put_pixel(center->minimap, (double)x + 100.0
						- center->player.x, (double)y + 100.0
						- center->player.y, 0x888888FF);
			}
			else
			{
				if (ft_still_inside(center, x, y))
					mlx_put_pixel(center->minimap, (double)x + 100.0
						- center->player.x, (double)y + 100.0
						- center->player.y, color);
			}
		}
	}
}

void	ft_set_color_minimap(t_gpt *center, int i, int j)
{
	int			x;
	int			y;
	const int	tmp_x = (int)((center->player.x / center->size));
	const int	tmp_y = (int)((center->player.y / center->size));

	i = tmp_y - 5;
	if (i < -1)
		i = -1;
	y = i * center->size;
	while (center->data->map[++i] && i < tmp_y + 5)
	{
		j = tmp_x - 5;
		if (j < -1)
			j = -1;
		x = j * center->size;
		while (center->data->map[i][++j] && j < tmp_x + 5)
		{
			ft_set_draw_around_color(center, center->data->map[i][j], x, y);
			x += center->size;
		}
		y += center->size;
	}
	ft_set_color_player(center);
}
