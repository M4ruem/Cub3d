/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:25:08 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/16 15:55:35 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_HEADER_H
# define RAYCASTER_HEADER_H

# include "../cub3d.h"

# define WIDTH 900
# define HEIGHT 900
# define PI 3.141592

typedef struct s_gpt	t_gpt;

void	ft_key_hook(void *arg);
void	ft_set_color_player(void *arg);
void	ft_set_color_minimap(void *arg);
int		ft_init_mlx(t_gpt *center);
void	ft_draw_map2D(t_gpt *center);
t_gpt	*ft_init_center(t_akinator *data);
void	ft_launch_raycasting(t_akinator *data);
void	ft_get_map_infos(t_gpt *center);
void	draw_pixel_around(mlx_image_t *img, int x, int y, int color);
int		ft_max_map_side(t_gpt *center);
void	ft_dda(t_gpt *center, int *p1, int *p2, int color);

#endif
