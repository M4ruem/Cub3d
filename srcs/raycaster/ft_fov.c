/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fov.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:51:15 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/27 16:41:58 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

int	ft_is_collision_for_ray(t_gpt *center, float px, float py)
{
	int	x;
	int	y;

	x = px / 25.0;
	y = py / 25.0;
	if (x < 0 || x >= center->map_width || y < 0 || y >= center->map_height)
		return (1);
	if (center->data->map[y][x] == '1')
		return (1);
	return (0);
}

static double	ft_horizontal_collisions(int *p1, t_gpt *center,
	const double cos_a, const double sin_a)
{
	double			dxyz[3];
	double			xy[2];
	double			dist;

	if (!sin_a)
		return (100000000000000000.0);
	if (sin_a > 0)
		dxyz[1] = 25;
	if (sin_a > 0)
		xy[1] = (p1[1] / 25 + 1) * 25;
	if (sin_a < 0)
		dxyz[1] = -25;
	if (sin_a < 0)
		xy[1] = (p1[1] / 25) * 25 - 0.0001;
	dist = (xy[1] - p1[1]) / sin_a;
	xy[0] = p1[0] + dist * cos_a;
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

static double	ft_vertical_collisions(int *p1, t_gpt *center,
	const double cos_a, const double sin_a)
{
	double			dxyz[3];
	double			xy[2];
	double			dist;

	if (!cos_a)
		return (100000000000000000.0);
	if (cos_a > 0)
		dxyz[0] = 25;
	if (cos_a > 0)
		xy[0] = (p1[0] / 25 + 1) * 25;
	if (cos_a < 0)
		dxyz[0] = -25;
	if (cos_a < 0)
		xy[0] = (p1[0] / 25) * 25 - 0.0001;
	dist = (xy[0] - p1[0]) / cos_a;
	xy[1] = p1[1] + dist * sin_a;
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

void	ft_fov(t_gpt *center, int *p1, double tmp_angle, int i)
{
	double			diff_angle;
	int				p2[2];
	double			eor_verti;
	double			eor;
	int				tm_p1[2];

	i = -1;
	tm_p1[0] = p1[0] + 100 - center->player.x;
	tm_p1[1] = p1[1] + 100 - center->player.y;
	diff_angle = (PI / 2.0) / (double)WIDTH;
	tmp_angle = center->player.angle - ((PI / 2.0) / 2.0);
	while (++i < WIDTH)
	{
		eor = ft_horizontal_collisions(p1, center, cosf(tmp_angle), \
			sinf(tmp_angle));
		eor_verti = ft_vertical_collisions(p1, center, \
			cosf(tmp_angle), sinf(tmp_angle));
		if (eor > eor_verti)
			eor = eor_verti;
		p2[0] = tm_p1[0] + (cosf(tmp_angle) * eor);
		p2[1] = tm_p1[1] + (sinf(tmp_angle) * eor);
		printf("p1[0] %i p1[1] %i\n", p1[0], p1[1]);
		ft_dda(center, tm_p1, p2, 0x0000FFFF);
		tmp_angle += diff_angle;
	}
}
