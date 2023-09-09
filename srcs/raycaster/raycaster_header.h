/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:25:08 by cormiere          #+#    #+#             */
/*   Updated: 2023/09/07 16:51:01 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_HEADER_H
# define RAYCASTER_HEADER_H

# include "../cub3d.h"

# define PI 3.141592653589
# define HORIZONTAL 0
# define VERTICAL 1
# define PLAYER_SIZE 9
# define HALF_PLAYER_SIZE 4
# define FOV 1.221730476
# define DEMI_FOV 0.610865238
# define MOUSE_SENSI 0.001

enum	e_side_wall
{
	TOP,
	BOTTOM,
	LEFT,
	RIGHT,
};

typedef struct s_ray_info
{
	double	x;
	double	y;
	double	dist;
}	t_ray_info;

typedef struct s_gpt	t_gpt;

void	ft_key_hook(void *arg);
void	ft_set_color_player(t_gpt *center);
void	ft_set_color_minimap(t_gpt *center, int i, int j);
int		ft_init_mlx(t_gpt *center);
void	ft_draw_map2D(t_gpt *center);
t_gpt	*ft_init_center(t_akinator *data);
void	ft_launch_raycasting(t_akinator *data);
void	ft_get_map_infos(t_gpt *center);
int		ft_max_map_side(t_gpt *center);
void	ft_dda(t_gpt *center, int *p1, int *p2, int color);
void	ft_adapt_player_moving(t_gpt *center, int key);
void	ft_fov(t_gpt *center, int i);
int		ft_out_of_range(int x, int y, mlx_image_t *img);
void	ft_trace_rays(t_gpt *center, int i);
void	ft_3d_making(t_gpt *center);
int		ft_adapt_color_floor(t_gpt *center);
int		ft_adapt_color_ceiling(t_gpt *center);
int		ft_still_inside(t_gpt *center, int x, int y);
int		ft_adapt_textures(t_gpt *center, int *xy, double dist_y);
void	ft_basic_mouvements(double *x, double *y, t_gpt *center);
void	ft_mouse_mouvement(t_gpt *center);
void	ft_set_draw_around_color(t_gpt *center, char c, int x, int y);
void	draw_pixel_around(t_gpt *center, int x, int y, int color);
#endif
