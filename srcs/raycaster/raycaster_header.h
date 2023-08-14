/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:25:08 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/14 14:30:44 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_HEADER_H
# define RAYCASTER_HEADER_H

# include "../cub3d.h"

# define WIDTH 600
# define HEIGHT 600

typedef struct s_gpt	t_gpt;

void	ft_key_hook(void *arg);
void	ft_set_color_player(void *arg);
void	ft_set_color_minimap(void *arg);
int		ft_init_mlx(t_gpt *center);
void	ft_draw_map2D(t_gpt *center);
t_gpt	*ft_init_center(t_akinator *data);
void	ft_launch_raycasting(t_akinator *data);

#endif
