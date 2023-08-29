/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:53 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/29 15:15:10 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

static void	ft_clear_image(t_gpt *center)
{
	int	x;
	int	y;

	x = 0;
	while (x < (int)center->minimap->height)
	{
		y = 0;
		while (y < (int)center->minimap->width)
		{
			mlx_put_pixel(center->minimap, x, y, 0x00000000);
			y++;
		}
		x++;
	}
}

static void	ft_four_mouvement(float *x, float *y, t_gpt *center)
{
	if (mlx_is_key_down(center->mlx, MLX_KEY_W))
	{
		*x = center->player.x + cosf(center->player.angle);
		*y = center->player.y + sinf(center->player.angle);
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_S))
	{
		*x = center->player.x - cosf(center->player.angle);
		*y = center->player.y - sinf(center->player.angle);
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_D))
	{
		*x = center->player.x + cosf(center->player.angle + (PI / 2.0));
		*y = center->player.y + sinf(center->player.angle + (PI / 2.0));
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_A))
	{
		*x = center->player.x - cosf(center->player.angle + (PI / 2.0));
		*y = center->player.y - sinf(center->player.angle + (PI / 2.0));
	}
}

int	ft_is_collision_for_player(t_gpt *center, float px, float py)
{
	int	x;
	int	y;

	x = px / 25.0;
	y = py / 25.0;
	if (center->data->map[y][x] == '1')
		return (1);
	return (0);
}

void	ft_key_hook(void *arg)
{
	t_gpt	*center;
	float	x;
	float	y;

	x = -1;
	y = -1;
	center = (t_gpt *)arg;
	if (mlx_is_key_down(center->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(center->mlx);
	ft_four_mouvement(&x, &y, center);
	if (!ft_is_collision_for_player(center, x, y))
	{
		center->player.x = x;
		center->player.y = y;
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_LEFT))
		center->player.angle -= 0.02;
	if (mlx_is_key_down(center->mlx, MLX_KEY_RIGHT))
		center->player.angle += 0.02;
	center->player.angle = fmod(center->player.angle, 6.28);
	// Calule distance -> tab
	ft_fov(center);
	// Dessin '3D'
	ft_3d_making(center);
	ft_clear_image(center);
	ft_set_color_minimap(center);
}
