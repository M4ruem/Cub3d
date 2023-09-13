/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_interpretation_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:54:15 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/13 18:34:10 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header_bonus.h"

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

static void	ft_wall_making(t_gpt *center, double screen_dist,
		int height_proj, int y_img)
{
	int			xy[2];
	int			y_tmp;
	double		dist;

	xy[0] = -1;
	while (++xy[0] < WIDTH)
	{
		dist = (center->fov[xy[0]].ray / (double)center->size) * \
			cosf((center->fov[xy[0]].angle - center->player.angle));
		height_proj = screen_dist;
		if (dist > 0)
			height_proj = (screen_dist / dist);
		xy[1] = (DEMI_HEIGHT) - (height_proj);
		height_proj <<= 1;
		y_img = -1;
		y_tmp = 0;
		if (xy[1] < 0)
			y_tmp = -xy[1];
		if (xy[1] < 0)
			xy[1] = 0;
		while (++y_img < height_proj && xy[1] + y_img < HEIGHT)
			mlx_put_pixel(center->fov_img, xy[0], xy[1] + y_img, \
			ft_adapt_textures(center, xy, (double)(y_img + y_tmp) \
			/ (double)height_proj));
	}
}

void	ft_3d_making(t_gpt *center)
{
	static double	screen_dist = 0;

	if (screen_dist == 0)
		screen_dist = ((double)DEMI_WIDTH / tan(PI / 4.0)) / 2.0;
	ft_floor_making(center);
	ft_ceiling_making(center);
	ft_wall_making(center, screen_dist, 0, 0);
}
