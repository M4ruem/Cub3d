/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_gestion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:34:22 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/30 16:02:43 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

// int	ft_adapt_textures(t_gpt *center, int *xy, int dist_y)
// {
// 	const double	tmp_x = (center->fov[xy[0]].x / 25.0) - \
// 		roundf(center->fov[xy[0]].x / 25.0);

// 	if (cosf(center->fov[xy[0]].angle) > 0 \
// 		&& center->fov[xy[0]].dir == HORIZONTAL)
// 		return (center->textures_tab.west->pixels[\
// 			(int)((center->textures_tab.west->width * tmp_x) + \
// 			(center->textures_tab.west->width * dist_y))]);
// 	else if (cosf(center->fov[xy[0]].angle) < 0 \
// 		&& center->fov[xy[0]].dir == HORIZONTAL)
// 		return (center->textures_tab.east->pixels[ \
// 			(int)((center->textures_tab.west->width * tmp_x) + \
// 			(center->textures_tab.west->width * dist_y))]);
// 	else if (sinf(center->fov[xy[0]].angle) > 0 \
// 		&& center->fov[xy[0]].dir == VERTICAL)
// 		return (center->textures_tab.north->pixels[\
// 			(int)((center->textures_tab.west->width * tmp_x) + \
// 			(center->textures_tab.west->width * dist_y))]);
// 	else if (sinf(center->fov[xy[0]].angle) < 0 \
// 		&& center->fov[xy[0]].dir == VERTICAL)
// 		return (center->textures_tab.south->pixels[\
// 			(int)((center->textures_tab.west->width * tmp_x) + \
// 			(center->textures_tab.west->width * dist_y))]);
// 	else
// 		return (0x7777FFFF);
// }