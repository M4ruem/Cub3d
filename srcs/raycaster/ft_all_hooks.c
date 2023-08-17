/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:53 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/17 18:42:46 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"


void	ft_adapt_player_moving(t_gpt *center, int key)
{
	const int	p1_xy[2] = {103, 103};
	float		steps;
	int	p2_xy[2];
	double	dxy[2];

	p2_xy[0] = p1_xy[0] + (cosf(center->a) * 20);
	p2_xy[1] = p1_xy[1] + (sinf(center->a) * 20);
	steps = abs(p2_xy[0] - p1_xy[0]);
	if (steps < abs(p2_xy[1] - p1_xy[1]))
		steps = abs(p2_xy[1] - p1_xy[1]);
	dxy[0] = (p2_xy[0] - p1_xy[0]) / steps;
	dxy[1] = (p2_xy[1] - p1_xy[1]) / steps;
	if (key == MLX_KEY_W)
	{
		center->player.pos->instances[0].x += dxy[0];
		center->player.pos->instances[0].y += dxy[1];
	}
	if (key == MLX_KEY_S)
	{
		center->player.pos->instances[0].x -= dxy[0];
		center->player.pos->instances[0].y -= dxy[1];
	}
	else
		
}

static void	ft_clear_image(t_gpt *center)
{
	int	x;
	int	y;

	x = 0;
	
	while (x < (int)center->player.pos->height)
	{
		y = 0;
		while (y < (int)center->player.pos->width)
		{
			mlx_put_pixel(center->player.pos, x, y, 0x00000000);
			y++;
		}
		x++;
	}
}

void	ft_key_hook(void *arg)
{
	t_gpt	*center;

	center = (t_gpt *)arg;
	ft_set_color_minimap(center);
	if (mlx_is_key_down(center->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(center->mlx);
	if (mlx_is_key_down(center->mlx, MLX_KEY_W))
	{
		center->player.pos->instances[0].y -= 1; 
		if (center->player.pos->instances[0].y < -100)
			center->player.pos->instances[0].y = -100;
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_S))
	{
		center->player.pos->instances[0].y += 1;
		if (center->player.pos->instances[0].y > 92)
			center->player.pos->instances[0].y = 92;
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_A))
	{
		center->player.pos->instances[0].x -= 1;
		if (center->player.pos->instances[0].x < -100)
			center->player.pos->instances[0].x = -100;
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_D))
	{
		center->player.pos->instances[0].x += 1;
		if (center->player.pos->instances[0].x > 92)
			center->player.pos->instances[0].x = 92;
	}

	center->player.y = (double)center->player.pos->instances[0].y / (double)200;
	center->player.x = (double)center->player.pos->instances[0].x / (double)200;
	printf("%f", center->player.x);
	printf(" %f\n", center->player.y);

	if (mlx_is_key_down(center->mlx, MLX_KEY_LEFT))
	{
		ft_clear_image(center);
		center->a -= 0.02;
		ft_set_color_player(center);
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_RIGHT))
	{
		ft_clear_image(center);
		center->a += 0.02;
		ft_set_color_player(center);
	}
	center->a = fmod(center->a, 6.28);
	// printf("dir x %f\t dir y  %f\n", cosf(center->a), sinf(center->a));
}