/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_interpretation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:54:15 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/04 16:39:11 by cormiere         ###   ########.fr       */
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
		while (y < HEIGHT / 2)
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
		y = HEIGHT / 2;
		while (y < HEIGHT)
		{
			mlx_put_pixel(center->fov_img, x, y,
					ft_adapt_color_floor(center));
			y++;
		}
		x++;
	}
}

static double	ft_get_y_progress(int *xy, int height_proj)
{
	double	tmp;

	tmp = (xy[1] - ((HEIGHT / 2) - (height_proj / 2)));
	if (tmp < 0)
		tmp = 0;
	tmp /= (((HEIGHT / 2) + (height_proj / 2)) - ((HEIGHT / 2) - (height_proj / 2)));
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
		xy[1] = (HEIGHT / 2) - (height_proj / 2);
		if (xy[1] < 0)
			xy[1] = 0;
		while (xy[1] < ((HEIGHT / 2) + (height_proj / 2)) && xy[1] < HEIGHT)
		{
			mlx_put_pixel(center->fov_img, xy[0], xy[1],
				ft_adapt_textures(center, xy, ft_get_y_progress(xy, height_proj)));
			xy[1]++;
		}
		xy[0]++;
	}
}

void	ft_3d_making(t_gpt *center)
{
	const double			screen_dist =  (WIDTH / 2) / tan(PI / 4.0);

	ft_floor_making(center);
	ft_ceiling_making(center);
	ft_wall_making(center, screen_dist);
}
