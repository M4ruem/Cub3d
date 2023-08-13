/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_raycasting.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:34:54 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/13 18:42:18 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycaster_header.h"

int		ft_put_image(t_gpt *center)
{
	if (mlx_image_to_window(center->mlx, center->minimap, 250, 250) == -1)
	{
		mlx_close_window(center->mlx);
		ft_free_center(center);
		puts(mlx_strerror(mlx_errno));
		return(0);
	}

	if (mlx_image_to_window(center->mlx, center->player, 280, 280) == -1)
	{
		mlx_close_window(center->mlx);
		ft_free_center(center);
		puts(mlx_strerror(mlx_errno));
		return(0);
	}
	mlx_loop_hook(center->mlx, /*ft_set_color2*/ft_draw_map2D, center->mlx);
	mlx_loop_hook(center->mlx, ft_set_color, center->mlx);
	mlx_loop_hook(center->mlx, ft_key_hook, center->mlx);
	return (1);
}

void	ft_launch_raycasting(t_akinator *data)
{
	t_gpt	*center;
	int		error;
	center = ft_init_center(data);
	if (!center)
		exit(EXIT_FAILURE);
	error = ft_put_image(center);
	if (!error)
		exit(EXIT_FAILURE);
	mlx_loop(center->mlx);
	mlx_terminate(center->mlx);
	return (1);
}
