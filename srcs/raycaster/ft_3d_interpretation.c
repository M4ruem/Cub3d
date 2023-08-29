/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_interpretation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:54:15 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/29 15:04:37 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

void	ft_ceiling_making(t_gpt *center)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
		{
			mlx_put_pixel(center->fov_img, x, y,
					ft_adapt_color_ceiling(center));
			y++;
		}
		x++;
	}
}

void	ft_floor_making(t_gpt *center)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = HEIGHT / 2;
		while (y < HEIGHT)
		{
			mlx_put_pixel(center->fov_img, x, y,
					ft_adapt_color_floor(center));
			y++;
		}
		x++;
	}
}

void	ft_wall_making(t_gpt *center, double screen_dist)
{
	int			height_proj;
	int				xy[2];
	double		dist;
	
	height_proj = 100;
	xy[0] = 0;
	while (xy[0] < WIDTH)
	{
		dist = center->fov[xy[0]].ray * \
			cosf((center->fov[xy[0]].angle - center->player.angle));
		if (center->fov[xy[0]].ray > 0)
			height_proj = roundf((screen_dist / dist) * 8.0);
		else
			height_proj = screen_dist;
		xy[1] = (HEIGHT / 2) - (height_proj);
		if (xy[1] < 0)
			xy[1] = 0;
		while (xy[1] < ((HEIGHT / 2) + (height_proj)))
		{
			mlx_put_pixel(center->fov_img, xy[0], xy[1], 0x7777FFFF);
			xy[1]++;
			if (xy[1] >= HEIGHT)
				break ;
		}
		xy[0]++;
	}
}

void	ft_3d_making(t_gpt *center)
{
	double			screen_dist;
	
	ft_floor_making(center);
	ft_ceiling_making(center);
	screen_dist = (WIDTH / 2) / tan(PI / 4.0);
	ft_wall_making(center, screen_dist);
}
