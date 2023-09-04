/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_interpretation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:54:15 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/04 17:08:05 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

void	ft_ceiling_making(t_gpt *center)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < DEMI_HEIGHT)
		{
			mlx_put_pixel(center->fov_img, x, y,
				ft_adapt_color_ceiling(center));
			y++;
		}
		x++;
	}
}

void	ft_floor_making(t_gpt *center)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = DEMI_HEIGHT;
		while (y < HEIGHT)
		{
			mlx_put_pixel(center->fov_img, x, y,
				ft_adapt_color_floor(center));
			y++;
		}
		x++;
	}
}

static double	ft_get_y_progress(int y, int height_proj)
{
	double	tmp;

	tmp = (y - ((DEMI_HEIGHT) - (height_proj)));
	if (tmp < 0)
		tmp = 0;
	tmp /= (((DEMI_HEIGHT) + (height_proj)) - ((DEMI_HEIGHT) - (height_proj)));
	return (tmp);
}

void	ft_wall_making(t_gpt *center, double screen_dist)
{
	int			height_proj;
	int			xy[2];
	double		dist;

	xy[0] = 0;
	while (xy[0] < WIDTH)
	{
		dist = (center->fov[xy[0]].ray / (double)center->size) * \
			cosf((center->fov[xy[0]].angle - center->player.angle));
		if (dist > 0)
			height_proj = (screen_dist / dist);
		else
			height_proj = screen_dist;
		xy[1] = (DEMI_HEIGHT) - (height_proj);
		if (xy[1] < 0)
			xy[1] = 0;
		while (xy[1] < ((DEMI_HEIGHT) + (height_proj)) && xy[1] < HEIGHT)
		{
			mlx_put_pixel(center->fov_img, xy[0], xy[1], ft_adapt_textures(\
				center, xy, ft_get_y_progress(xy[1], height_proj)));
			xy[1]++;
		}
		xy[0]++;
	}
}

void	ft_3d_making(t_gpt *center)
{
	static double	screen_dist = 0;

	if (screen_dist == 0)
		screen_dist = (double)DEMI_WIDTH / tan(PI / 4.0) / 2.0;
	ft_floor_making(center);
	ft_ceiling_making(center);
	ft_wall_making(center, screen_dist);
}
