/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_raycasting_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:34:54 by cormiere          #+#    #+#             */
/*   Updated: 2023/09/14 15:42:29 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header_bonus.h"

int	ft_put_image(t_gpt *center)
{
	if (mlx_image_to_window(center->mlx, center->minimap, 0, 0) == -1)
	{
		mlx_close_window(center->mlx);
		ft_free_center(center);
		puts(mlx_strerror(mlx_errno));
		return (0);
	}
	if (mlx_image_to_window(center->mlx, center->fov_img, 0, 0) == -1)
	{
		mlx_close_window(center->mlx);
		ft_free_center(center);
		puts(mlx_strerror(mlx_errno));
		return (0);
	}
	center->minimap->instances->z = 1;
	center->fov_img->instances->z = 0;
	mlx_set_cursor_mode(center->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(center->mlx, DEMI_WIDTH, DEMI_HEIGHT);
	mlx_loop_hook(center->mlx, ft_key_hook, center);
	return (1);
}

void	ft_launch_raycasting(t_akinator *data)
{
	t_gpt	*center;
	int		error;

	error = 0;
	center = ft_init_center(data);
	if (!center)
		exit(EXIT_FAILURE);
	error = ft_put_image(center);
	if (!error)
		exit(EXIT_FAILURE);
	mlx_loop(center->mlx);
	mlx_terminate(center->mlx);
	ft_free_center(center);
}
