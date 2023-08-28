/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:25:08 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/28 14:42:34 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_HEADER_H
# define RAYCASTER_HEADER_H

# include "../cub3d.h"

# define PI 3.141592653589

typedef struct s_gpt	t_gpt;

void	ft_key_hook(void *arg);
void	ft_set_color_player(t_gpt *center);
void	ft_set_color_minimap(t_gpt *center);
int		ft_init_mlx(t_gpt *center);
void	ft_draw_map2D(t_gpt *center);
t_gpt	*ft_init_center(t_akinator *data);
void	ft_launch_raycasting(t_akinator *data);
void	ft_get_map_infos(t_gpt *center);
int		ft_max_map_side(t_gpt *center);
void	ft_dda(t_gpt *center, int *p1, int *p2, int color);
void	ft_adapt_player_moving(t_gpt *center, int key);
void	ft_fov(t_gpt *center);
int		ft_out_of_range(int x, int y, mlx_image_t *img);
void	ft_trace_rays(t_gpt *center);
void	ft_3d_making(t_gpt *center);

#endif
