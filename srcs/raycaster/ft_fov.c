/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:51:15 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/04 16:41:10 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

int	ft_is_collision_for_ray(t_gpt *center, double px, double py)
{
	int	x;
	int	y;

	x = px / 25;
	y = py / 25;
	if (x < 0 || x >= center->map_width || y < 0 || y >= center->map_height)
		return (1);
	if (center->data->map[y][x] == '1')
		return (1);
	return (0);
}

static double	ft_horizontal_collisions(t_gpt *center,
	const double cos_a, const double sin_a)
{
	double			dxyz[3];
	double			xy[2];
	double			dist;

	if (!sin_a)
		return (100000000000000000.0);
	if (sin_a > 0.0)
	{
		dxyz[1] = (double)center->size;
		xy[1] = ((int)center->player.y / center->size + 1) * (double)center->size;
	}
	else if (sin_a < 0.0)
	{
		dxyz[1] = -(double)center->size;
		xy[1] = ((int)center->player.y / center->size) * (double)center->size - 0.0001;
	}
	dist = (double)(xy[1] - (int)center->player.y) / sin_a;
	xy[0] = (int)center->player.x + dist * cos_a;
	dxyz[2] = dxyz[1] / sin_a;
	dxyz[0] = dxyz[2] * cos_a;
	while (!ft_is_collision_for_ray(center, xy[0], xy[1]))
	{
		xy[0] += dxyz[0];
		xy[1] += dxyz[1];
		dist += dxyz[2];
	}
	return (dist);
}

static double	ft_vertical_collisions(t_gpt *center,
	const double cos_a, const double sin_a)
{
	double			dxyz[3];
	double			xy[2];
	double			dist;

	if (!cos_a)
		return (100000000000000000.0);
	if (cos_a > 0.0)
	{
		dxyz[0] = (double)center->size;
		xy[0] = ((int)center->player.x / center->size + 1) * (double)center->size;
	}
	else if (cos_a < 0.0)
	{
		dxyz[0] = -(double)center->size;
		xy[0] = ((int)center->player.x / center->size) * (double)center->size - 0.0001;
	}
	dist = (double)(xy[0] - (int)center->player.x) / cos_a;
	xy[1] = (int)center->player.y + dist * sin_a;
	dxyz[2] = dxyz[0] / cos_a;
	dxyz[1] = dxyz[2] * sin_a;
	while (!ft_is_collision_for_ray(center, xy[0], xy[1]))
	{
		xy[0] += dxyz[0];
		xy[1] += dxyz[1];
		dist += dxyz[2];
	}
	return (dist);
}

void	ft_fov(t_gpt *center, int i, double eor)
{
	const double	diff_angle = (70.0 * PI / 180.0) / (double)WIDTH;
	double	eor_verti;
	double tmp_angle;
	double start_angle;

	start_angle = center->player.angle - ((70 * PI / 180.0) / 2.0);
	while (++i < WIDTH)
	{
		tmp_angle = start_angle + diff_angle * i;
		eor = ft_horizontal_collisions(center, cos(tmp_angle), \
			sin(tmp_angle));
		eor_verti = ft_vertical_collisions(center, \
			cos(tmp_angle), sin(tmp_angle));
		center->fov[i].dir = HORIZONTAL;
		if (eor > eor_verti)
		{	eor = eor_verti;
			center->fov[i].dir =  VERTICAL;
		}
		center->fov[i].ray = eor;
		center->fov[i].angle = tmp_angle;
		center->fov[i].x = center->player.x  + (cos(tmp_angle) * eor);
		center->fov[i].y = center->player.y  + (sin(tmp_angle) * eor);
	}
}

void	ft_trace_rays(t_gpt *center)
{
	int		i;
	int		tm_p1[2];
	double	tmp_angle;
	double	diff_angle;
	int		p2[2];

	tm_p1[0] = 100;
	tm_p1[1] = 100;
	i = -1;
	diff_angle = (70 * PI / 180) / (double)WIDTH;
	tmp_angle = center->player.angle - ((70 * PI / 180) / 2.0);
	while (++i < WIDTH)
	{
		p2[0] = tm_p1[0] + (cos(tmp_angle) * center->fov[i].ray);
		p2[1] = tm_p1[1] + (sin(tmp_angle) * center->fov[i].ray);
		ft_dda(center, tm_p1, p2, 0x0000FFFF);
		tmp_angle += diff_angle;
	}
}
