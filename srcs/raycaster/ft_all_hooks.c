/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:53 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/04 17:34:02 by cormiere         ###   ########.fr       */
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

static void	ft_all_mouvements(double *x, double *y, t_gpt *center)
{
	if (mlx_is_key_down(center->mlx, MLX_KEY_LEFT))
		center->player.angle -= 0.03;
	if (mlx_is_key_down(center->mlx, MLX_KEY_RIGHT))
		center->player.angle += 0.03;
	if (mlx_is_key_down(center->mlx, MLX_KEY_W))
	{
		*x += cos(center->player.angle) * 1.5;
		*y += sin(center->player.angle) * 1.5;
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_S))
	{
		*x -= cos(center->player.angle) * 1.5;
		*y -= sin(center->player.angle) * 1.5;
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_D))
	{
		*x -= sin(center->player.angle) * 1.5;
		*y += cos(center->player.angle) * 1.5;
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_A))
	{
		*x += sin(center->player.angle) * 1.5;
		*y -= cos(center->player.angle) * 1.5;
	}
}

static int	ft_is_collision_for_player(t_gpt *center, double px, double py)
{
	const int	p1[2] = {px / (double)center->size, \
		(py - 2) / (double)center->size};
	const int	p2[2] = {(px - 3) / (double)center->size, \
		py / (double)center->size};
	const int	p3[2] = {(px + 3) / (double)center->size, \
		py / (double)center->size};
	const int	p4[2] = {px / (double)center->size, \
		(py + 5) / (double)center->size};

	if (center->data->map[p1[1]][p1[0]] == '1'
		|| center->data->map[p2[1]][p2[0]] == '1'
		|| center->data->map[p3[1]][p3[0]] == '1'
		|| center->data->map[p4[1]][p4[0]] == '1')
		return (1);
	return (0);
}

void	ft_key_hook(void *arg)
{
	t_gpt	*center;
	double	x;
	double	y;

	center = (t_gpt *)arg;
	x = center->player.x;
	y = center->player.y;
	if (mlx_is_key_down(center->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(center->mlx);
	ft_all_mouvements(&x, &y, center);
	if (!ft_is_collision_for_player(center, x, y))
	{
		center->player.x = roundf(x);
		center->player.y = roundf(y);
	}
	center->player.angle = fmod(center->player.angle, 6.28);
	ft_fov(center, -1, 0.0);
	ft_clear_image(center);
	ft_3d_making(center);
	ft_set_color_minimap(center);
}
