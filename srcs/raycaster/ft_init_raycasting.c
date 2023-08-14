/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:31:28 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/14 17:14:19 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

int	ft_max_map_side(t_gpt *center)
{
	if (center->map_height > center->map_width)
		return (center->map_height);
	else
		return (center->map_width);
}

t_gpt	*ft_init_center(t_akinator *data)
{
	t_gpt	*center;
	int		error;

	error = 0;
	center = ft_calloc(sizeof(t_gpt), 1);
	if (!center)
		return (NULL);
	center->data = data;
	ft_get_map_infos(center);
	error = ft_init_mlx(center);
	if (!error)
		ft_free_center(center);
	return (center);
}

void	ft_key_hook(void *arg)
{
	t_gpt	*center;

	center = (t_gpt *)arg;
	if (mlx_is_key_down(center->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(center->mlx);
	if (mlx_is_key_down(center->mlx, MLX_KEY_UP))
		center->player->instances[0].y -= 5;
	if (mlx_is_key_down(center->mlx, MLX_KEY_DOWN))
		center->player->instances[0].y += 5;
	if (mlx_is_key_down(center->mlx, MLX_KEY_LEFT))
		center->player->instances[0].x -= 5;
	if (mlx_is_key_down(center->mlx, MLX_KEY_RIGHT))
		center->player->instances[0].x += 5;
}

int	ft_init_mlx(t_gpt *center)
{
	center->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	if (!center->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (0);
	}
	center->minimap = mlx_new_image(center->mlx, ((WIDTH / 8)), HEIGHT / 8);
	if (!center->minimap)
	{
		mlx_close_window(center->mlx);
		puts(mlx_strerror(mlx_errno));
		return (0);
	}
	center->player = mlx_new_image(center->mlx,
		((WIDTH / 8 / ft_max_map_side(center)) / 3,
		((WIDTH / 8 / ft_max_map_side(center))) / 3);
	if (!center->player)
	{
		mlx_close_window(center->mlx);
		puts(mlx_strerror(mlx_errno));
		return (0);
	}
	return (1);
}
