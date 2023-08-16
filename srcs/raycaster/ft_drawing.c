/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:30:06 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/14 19:24:59 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

/*
void mlx_draw_line(t_gpt *center, int x0, int y0, int x1, int y1, int color)
{
    int dx = abs(x1 - x0);
    int sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0);
    int sy = y0 < y1 ? 1 : -1;
    int err = dx + dy;

    while (1)
    {
        mlx_pixel_put(center->player.pos, x0, y0, color);
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void ft_set_player_color(void *arg)
{
	t_gpt	*center;
	int		x;
	int		y;
	center = (t_gpt *)arg;
    mlx_pixel_put(center->player.pos, x, y, 0xFFFF00);

    int line_end_x = px + pdx * 20;
    int line_end_y = py + pdy * 20;
    mlx_draw_line(center->player.pos, x, y, line_end_x, line_end_y, 0xFFFF00);
}*/


void	ft_set_color_player(void *arg)
{
	t_gpt	*center;
	int		x;
	int		y;

	center = (t_gpt *)arg;
	x = 0;
	while (x < (int)center->player.pos->width)
	{
		y = 0;
		while (y < (int)center->player.pos->height)
		{
			mlx_put_pixel(center->player.pos, x, y, 0xFF00FFFF);
			y++;
		}
		x++;
	}
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

void	ft_set_color_minimap(void *arg)
{
	t_gpt	*center;
	int		x;
	int		y;
	int		i;
	int		j;

	i = 0;
	center = (t_gpt *)arg;
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
