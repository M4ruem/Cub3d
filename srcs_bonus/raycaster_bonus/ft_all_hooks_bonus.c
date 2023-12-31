/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_hooks_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:29:53 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/13 18:34:13 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header_bonus.h"
#include <sys/time.h>

static void	ft_print_fps(t_gpt *center)
{
	char			title[9];
	int				tmp;

	title[0] = 'f';
	title[1] = 'p';
	title[2] = 's';
	title[3] = ' ';
	title[4] = ':';
	title[5] = ' ';
	tmp = roundf(1.0 / center->mlx->delta_time);
	title[6] = (tmp / 10) + '0';
	title[7] = (tmp % 10) + '0';
	title[8] = '\0';
	mlx_set_window_title(center->mlx, title);
}

static void	ft_clear_image(t_gpt *center)
{
	int	x;
	int	y;

	x = 0;
	while (x < (int)center->minimap->height)
	{
		y = 0;
		while (y < (int)center->minimap->width)
		{
			mlx_put_pixel(center->minimap, x, y, 0x00000000);
			y++;
		}
		x++;
	}
}

static int	ft_is_collision_for_player(t_gpt *center, double px, double py)
{
	const int	p1[2] = {px / (double)center->size, \
		(py - 2) / (double)center->size};
	const int	p2[2] = {(px - 3) / (double)center->size, \
		py / (double)center->size};
	const int	p3[2] = {(px + 3) / (double)center->size, \
		py / (double)center->size};
	const int	p4[2] = {px / (double)center->size, \
		(py + 5) / (double)center->size};

	if (center->data->map[p1[1]][p1[0]] == '1'
		|| center->data->map[p2[1]][p2[0]] == '1'
		|| center->data->map[p3[1]][p3[0]] == '1'
		|| center->data->map[p4[1]][p4[0]] == '1')
		return (1);
	return (0);
}

void	ft_trace_rays(t_gpt *center, int i)
{
	double			cos_sin_angle[2];
	static int		tm_p1[2] = {100, 100};
	double			tmp_angle;
	static double	diff_angle = FOV / (double)WIDTH;
	int				p2[2];

	i = -1;
	tmp_angle = center->player.angle - DEMI_FOV;
	while (++i < WIDTH)
	{
		cos_sin_angle[0] = cos(tmp_angle);
		cos_sin_angle[1] = sin(tmp_angle);
		p2[0] = tm_p1[0] + (cos_sin_angle[0] * center->fov[i].ray);
		p2[1] = tm_p1[1] + (cos_sin_angle[1] * center->fov[i].ray);
		ft_dda(center, tm_p1, p2, 0x0000FFFF);
		tmp_angle += diff_angle;
	}
}

void	ft_key_hook(void *arg)
{
	t_gpt	*center;
	double	x;
	double	y;

	center = (t_gpt *)arg;
	x = center->player.x;
	y = center->player.y;
	if (mlx_is_key_down(center->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(center->mlx);
	ft_basic_mouvements(&x, &y, center);
	ft_mouse_mouvement(center);
	if (!ft_is_collision_for_player(center, x, y))
	{
		center->player.x = roundf(x);
		center->player.y = roundf(y);
	}
	center->player.angle = fmod(center->player.angle, 6.28);
	ft_fov(center, -1);
	ft_clear_image(center);
	ft_3d_making(center);
	ft_set_color_minimap(center, 0, 0);
	ft_print_fps(center);
}
