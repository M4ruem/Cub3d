/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:31:28 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/14 19:44:38 by cormiere         ###   ########.fr       */
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

typedef struct s_vec
{
	double x;
	double y;
}		t_vec;

//NORTH (0, -1)
//SUD (0, 1)
//OUEST(-1, 0)
//EST (1, 0)

/*void    ft_dda(t_data *data, t_map p1, t_map p2, int color)
{
	float    steps;
	float    x;
	float    y;
	int        i;

	steps = fabs(p2.x - p1.x);
	if (steps < fabs(p2.y - p1.y))
		steps = fabs(p2.y - p1.y);
	data->coord.dx = (p2.x - p1.x) / steps;
	data->coord.dy = (p2.y - p1.y) / steps;
	x = p1.x + 0.5f;
	y = p1.y + 0.5f;
	i = 1;
	while (i <= steps + 1)
	{
		ft_put_pixel(data, x, y, color);
		x += data->coord.dx;
		y += data->coord.dy;
		i++;
	}
}*/

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
	center->player.y = (double)center->player.pos->instances[0].y / 200;
	center->player.x = (double)center->player.pos->instances[0].x / 200;
	printf("%f", center->player.x);
	printf(" %f\n", center->player.y);
	/*	if (mlx_is_key_down(center->mlx, MLX_KEY_UP))
	{

	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_DOWN))
	{

	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_LEFT))
	{

	}
	if (mlx_is_key_down(center->mlx, MLX_KEY_RIGHT))
	{

	}*/
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
	center->player.pos = mlx_new_image(center->mlx,
		((((WIDTH / 6) / ft_max_map_side(center))) / 3),
		((((WIDTH / 6) / ft_max_map_side(center)))) / 3);
	if (!center->player.pos)
	{
		mlx_close_window(center->mlx);
		puts(mlx_strerror(mlx_errno));
		return (0);
	}
	return (1);
}
