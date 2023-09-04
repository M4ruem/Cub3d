/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_mouvement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 17:32:10 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/04 17:59:36 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

static void	ft_forward_backward(double *x, double *y, t_gpt *center)
{
	if (mlx_is_key_down(center->mlx, MLX_KEY_W) && !mlx_is_key_down(center->mlx,
			MLX_KEY_S) && !mlx_is_key_down(center->mlx, MLX_KEY_D)
		&& !mlx_is_key_down(center->mlx, MLX_KEY_A))
	{
		*x += cos(center->player.angle) * 1.5;
		*y += sin(center->player.angle) * 1.5;
	}
	else if (mlx_is_key_down(center->mlx, MLX_KEY_S) && !mlx_is_key_down(
			center->mlx, MLX_KEY_W) && !mlx_is_key_down(center->mlx, MLX_KEY_D)
		&& !mlx_is_key_down(center->mlx, MLX_KEY_A))
	{
		*x -= cos(center->player.angle) * 1.25;
		*y -= sin(center->player.angle) * 1.25;
	}
}

static void	ft_left_right(double *x, double *y, t_gpt *center)
{
	if (mlx_is_key_down(center->mlx, MLX_KEY_D) && !mlx_is_key_down(
			center->mlx, MLX_KEY_W) && !mlx_is_key_down(center->mlx, MLX_KEY_S)
		&& !mlx_is_key_down(center->mlx, MLX_KEY_A))
	{
		*x -= sin(center->player.angle) * 1.25;
		*y += cos(center->player.angle) * 1.25;
	}
	else if (mlx_is_key_down(center->mlx, MLX_KEY_A) && !mlx_is_key_down(\
			center->mlx, MLX_KEY_W) && !mlx_is_key_down(center->mlx, MLX_KEY_S)\
		&& !mlx_is_key_down(center->mlx, MLX_KEY_D))
	{
		*x += sin(center->player.angle) * 1.5;
		*y -= cos(center->player.angle) * 1.5;
	}
}

static void	ft_forward_diagonals(double *x, double *y, t_gpt *center)
{
	if (mlx_is_key_down(center->mlx, MLX_KEY_W) && mlx_is_key_down(center->mlx,
			MLX_KEY_A))
	{
		*x += cos(center->player.angle) * 0.60;
		*y += sin(center->player.angle) * 0.60;
		*x += sin(center->player.angle) * 0.60;
		*y -= cos(center->player.angle) * 0.60;
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_W) && mlx_is_key_down(center->mlx,
			MLX_KEY_D))
	{
		*x += cos(center->player.angle) * 0.60;
		*y += sin(center->player.angle) * 0.60;
		*x -= sin(center->player.angle) * 0.60;
		*y += cos(center->player.angle) * 0.60;
	}
}

static void	ft_backward_diagonals(double *x, double *y, t_gpt *center)
{
	if (mlx_is_key_down(center->mlx, MLX_KEY_S) && mlx_is_key_down(
			center->mlx, MLX_KEY_A))
	{
		*x -= cos(center->player.angle) * 0.60;
		*y -= sin(center->player.angle) * 0.60;
		*x += sin(center->player.angle) * 0.60;
		*y -= cos(center->player.angle) * 0.60;
	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_S) && mlx_is_key_down(
			center->mlx, MLX_KEY_D))
	{
		*x -= cos(center->player.angle) * 0.60;
		*y -= sin(center->player.angle) * 0.60;
		*x -= sin(center->player.angle) * 0.60;
		*y += cos(center->player.angle) * 0.60;
	}
}

void	ft_basic_mouvements(double *x, double *y, t_gpt *center)
{
	ft_forward_backward(x, y, center);
	ft_left_right(x, y, center);
	ft_forward_diagonals(x, y, center);
	ft_backward_diagonals(x, y, center);
	if (mlx_is_key_down(center->mlx, MLX_KEY_LEFT))
		center->player.angle -= 0.03;
	if (mlx_is_key_down(center->mlx, MLX_KEY_RIGHT))
		center->player.angle += 0.03;
}