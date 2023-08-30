/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:31:28 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/29 19:18:47 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

static double	ft_adapt_sens(t_gpt *center)
{
	if (center->player_start_sens == 'S')
		return (PI / 2);
	else if (center->player_start_sens == 'W')
		return (PI);
	else if (center->player_start_sens == 'N')
		return (PI * 1.5);
	else
		return (0.0);
}

int	ft_max_map_side(t_gpt *center)
{
	if (center->map_height > center->map_width)
		return (center->map_height);
	else
		return (center->map_width);
}

static int	ft_init_textures(t_gpt *center)
{
	center->textures_tab.north = mlx_load_png(center->data->texture_paths[0]);
	if (!center->textures_tab.north)
	{
		puts(mlx_strerror(mlx_errno));
		return (0);
	}
	center->textures_tab.south = mlx_load_png(center->data->texture_paths[1]);
	if (!center->textures_tab.south)
	{
		puts(mlx_strerror(mlx_errno));
		return (0);
	}
	center->textures_tab.east = mlx_load_png(center->data->texture_paths[2]);
	if (!center->textures_tab.east)
	{
		puts(mlx_strerror(mlx_errno));
		return (0);
	}
	center->textures_tab.west = mlx_load_png(center->data->texture_paths[3]);
	if (!center->textures_tab.west)
	{
		puts(mlx_strerror(mlx_errno));
		return (0);
	}
	return (1);
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
	center->player.angle = ft_adapt_sens(center);
	error = ft_init_textures(center);
	if (!error)
		ft_free_center(center);
	return (center);
}

int	ft_init_mlx(t_gpt *center)
{
	center->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", false);
	if (!center->mlx)
	{
		puts(mlx_strerror(mlx_errno));
		return (0);
	}
	center->minimap = mlx_new_image(center->mlx, 200, 200);
	if (!center->minimap)
	{
		mlx_close_window(center->mlx);
		puts(mlx_strerror(mlx_errno));
		return (0);
	}
	center->fov_img = mlx_new_image(center->mlx, WIDTH, HEIGHT);
	if (!center->fov_img)
	{
		mlx_close_window(center->mlx);
		puts(mlx_strerror(mlx_errno));
		return (0);
	}
	return (1);
}
