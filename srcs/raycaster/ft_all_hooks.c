/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:53 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/17 17:02:08 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

void	ft_clear_image(t_gpt *center)
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
	if (mlx_is_key_down(center->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(center->mlx);
	if (mlx_is_key_down(center->mlx, MLX_KEY_W))
	{
		center->player.pos->instances[0].y -= 1;
		if (center->player.pos->instances[0].y < 0)
			center->player.pos->instances[0].y = 0;
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_S))
	{
		center->player.pos->instances[0].y += 1;
		if (center->player.pos->instances[0].y > 194)
			center->player.pos->instances[0].y = 194;
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_A))
	{
		center->player.pos->instances[0].x -= 1;
		if (center->player.pos->instances[0].x < 0)
			center->player.pos->instances[0].x = 0;
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_D))
	{
		center->player.pos->instances[0].x += 1;
		if (center->player.pos->instances[0].x > 194)
			center->player.pos->instances[0].x = 194;
	}

	center->player.y = (double)center->player.pos->instances[0].y / (double)200;
	center->player.x = (double)center->player.pos->instances[0].x / (double)200;
	printf("%f", center->player.x);
	printf(" %f\n", center->player.y);

	if (mlx_is_key_down(center->mlx, MLX_KEY_LEFT))
	{
		ft_clear_image(center);
		center->a -= 0.02;
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_RIGHT))
	{
		ft_clear_image(center);
		center->a += 0.02;
	}
	center->a = fmod(center->a, 6.28);
	// printf("dir x %f\t dir y  %f\n", cosf(center->a), sinf(center->a));
}