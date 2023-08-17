/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:30:06 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/17 16:01:54 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

// static void	ft_drawing_in_sens(t_gpt *center, int *p1, int *p2)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < 2)
// 	{
// 		ft_dda(center, p1, p2, 0xFF00FFFF);
// 		if (center->player_start_sens == 'S'
// 			|| center->player_start_sens == 'N')
// 		{
// 			p1[0]++;
// 			p2[0]++;
// 		}
// 		else if (center->player_start_sens == 'W'
// 			|| center->player_start_sens == 'E')
// 		{
// 			p1[1]--;
// 			p2[1]--;
// 		}
// 	}
// }

// static void	ft_ajust_sens_fov(t_gpt *center, int *p1, int *p2)
// {
// 	if (center->player_start_sens == 'S')
//  	{
// 		p1[0] += 2;
// 		p1[1] += 10;
// 		p2[0] += 2;
// 	}
// 	else if (center->player_start_sens == 'N')
// 	{
// 		p1[0] += 2;
// 		p1[1] -= 15;
// 		p2[0] += 2;
// 	}
// 	else if (center->player_start_sens == 'E')
// 	{
// 		p1[0] += 3;
// 		p1[1] -= 2;
// 		p2[0] += 15;
// 		p2[1] -= 2;
// 	}
// 	else
// 	{
// 		p1[1] -= 2;
// 		p2[0] -= 10;
// 		p2[1] -= 2;
// 	}
// }

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


void	ft_set_color_player(void *arg)
{
	t_gpt	*center;
	int		x;
	int		y;

	center = (t_gpt *)arg;
	x = -1;
	
	while (++x < (int)(center->player.pos->width / ft_max_map_side(center) / 3))
	{
		y = -1;
		while (++y < (int)(center->player.pos->height \
			/ ft_max_map_side(center) / 3))
			mlx_put_pixel(center->player.pos, x + 100, y + 100, 0xFF00FFFF);
	}

	int tmp[2];
	tmp[0] = center->player.pos->instances[0].x;
	tmp[1] = center->player.pos->instances[0].y;
	int end[2];
	end[0] = tmp[0] + (cosf(center->a) * 50);
	end[1] = tmp[1]+ (sinf(center->a) * 50);

// float  tmp[2] = {center->player.x, center->player.y };
// 	printf("%f %f\n", (double)tmp[0], (double)tmp[1]);
	ft_dda(center, tmp, end, 0xFF00FFFF);
	// ft_ajust_sens_fov(center, tmp, tmp_2);
	// x = 0;
	// ft_drawing_in_sens(center, tmp, tmp_2);
	
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

// void	black_screen(void *arg)
// {
// 	int x = 0;
// 	int y = 0 ;
// 	t_gpt *center = (t_gpt *)arg;
// 	while (x < (int)center->player.pos->height)
// 	{
// 		x = 0;
// 		while (y < (int)center->player.pos->width)
// 		{
// 			mlx_put_pixel(center->player.pos, y, x, 0x000000FF);
// 			y++;
// 		}
// 		x++;
// 	}
// }

void	ft_set_color_minimap(void *arg)
{
	t_gpt	*center;
	int		x;
	int		y;
	int		i;
	int		j;

	i = 0;
	center = (t_gpt *)arg;
	// black_screen(arg);
	y = 0;
	while (y < (int)center->minimap->width && center->data->map[i])
	{
		j = 0;
		x = 0;
		while (x < (int)center->minimap->height && center->data->map[i][j])
		{
			if (center->data->map[i][j] == '1')
				draw_pixel_around(center->minimap, x, y, 0x000000FF);
			else
				draw_pixel_around(center->minimap, x, y, 0x000000FF);
			x += 25; /// 8 / ft_max_map_side(center)));
			j++;
		}
		y += 25; // / 8 / ft_max_map_side(center)));
		i++;
	}
}
