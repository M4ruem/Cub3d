/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:25:08 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/13 18:10:47 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	RAYCASTER_HEADER_H
# define RAYCASTER_HEADER_H

#include "../cub3d.h"

#define WIDTH 600
#define HEIGHT 600

void	ft_key_hook(t_gpt *center);
void	ft_set_color(t_gpt *center);
int		ft_init_mlx(t_gpt *center);
void	ft_draw_map2D(void *arg);
t_gpt	*ft_init_center(t_akinator *data);



#endif
