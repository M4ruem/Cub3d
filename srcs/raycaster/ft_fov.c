/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:51:15 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/05 17:45:26 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

int	ft_is_collision_for_ray(t_gpt *center, double px, double py)
{
	int	x;
	int	y;

	x = px / center->size;
	y = py / center->size;
	if (x < 0 || x >= center->map_width || y < 0 || y >= center->map_height)
		return (1);
	if (center->data->map[y][x] == '1')
		return (1);
	return (0);
}

static t_ray_info	ft_horizontal_collisions(t_gpt *center,
	const double cos_a, const double sin_a)
{
	double			dxyz[3];
	static t_ray_info		ray = {0.0, 0.0, 0.0};

	if (!sin_a)
		return (ray);
	if (sin_a > 0.0)
	{
		dxyz[1] = (double)center->size;
		ray.y = ((int)center->player.y / center->size + 1) * (double)center->size;
	}
	else if (sin_a < 0.0)
	{
		dxyz[1] = -(double)center->size;
		ray.y = ((int)center->player.y / center->size) * (double)center->size - 0.0001;
	}
	ray.dist = (double)(ray.y - (int)center->player.y) / sin_a;
	ray.x = (int)center->player.x + ray.dist * cos_a;
	dxyz[2] = dxyz[1] / sin_a;
	dxyz[0] = dxyz[2] * cos_a;
	while (!ft_is_collision_for_ray(center, ray.x, ray.y))
	{
		ray.x += dxyz[0];
		ray.y += dxyz[1];
		ray.dist += dxyz[2];
	}
	return (ray);
}

static t_ray_info	ft_vertical_collisions(t_gpt *center,
	const double cos_a, const double sin_a)
{
	double			dxyz[3];
	static t_ray_info		ray = {0.0, 0.0, 0.0};

	if (!cos_a)
		return (ray);
	if (cos_a > 0.0)
	{
		dxyz[0] = (double)center->size;
		ray.x = ((int)center->player.x / center->size + 1) * (double)center->size;
	}
	else if (cos_a < 0.0)
	{
		dxyz[0] = -(double)center->size;
		ray.x = ((int)center->player.x / center->size) * (double)center->size - 0.0001;
	}
	ray.dist = (double)(ray.x - (int)center->player.x) / cos_a;
	ray.y = (int)center->player.y + ray.dist * sin_a;
	dxyz[2] = dxyz[0] / cos_a;
	dxyz[1] = dxyz[2] * sin_a;
	while (!ft_is_collision_for_ray(center, ray.x, ray.y))
	{
		ray.x += dxyz[0];
		ray.y += dxyz[1];
		ray.dist += dxyz[2];
	}
	return (ray);
}

static t_ray_info	ft_which_collisions(t_gpt *center, double cos_angle,
		double sin_angle, int i)
{
	t_ray_info	ray;
	t_ray_info	ray_verti;
	
	ray = ft_horizontal_collisions(center, cos_angle, sin_angle);
	ray_verti = ft_vertical_collisions(center, cos_angle, sin_angle);
	center->fov[i].dir = BOTTOM;
	if (ray.dist > ray_verti.dist)
	{
		ray = ray_verti;
		center->fov[i].dir = RIGHT;
		if (cos_angle > 0)
			center->fov[i].dir = LEFT;
	}
	else if (sin_angle > 0)
			center->fov[i].dir = TOP;
	return (ray);
}

void	ft_fov(t_gpt *center, int i)
{
	static double	diff_angle = FOV / (double)WIDTH;
	double			tmp_angle;
	t_ray_info		ray;
	double			start_angle;
	double			cos_sin_angle[2];

	start_angle = center->player.angle - DEMI_FOV;
	while (++i < WIDTH)
	{
		tmp_angle = start_angle + diff_angle * i;
		cos_sin_angle[0] = cos(tmp_angle);
		cos_sin_angle[1] = sin(tmp_angle);
		ray = ft_which_collisions(center, cos_sin_angle[0], cos_sin_angle[1],
				i);
		center->fov[i].ray = ray.dist;
		center->fov[i].angle = tmp_angle;
		center->fov[i].x = ray.x;
		center->fov[i].y = ray.y;
	}
}