/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:32:33 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/14 17:38:23 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

void	ft_get_map_infos(t_gpt *center)
{
	int	x;
	int	y;

	x = 0;
	center->map_height = ft_array_len(center->data->map);
	center->map_width = ft_max_line(center->data->map);
	while (center->data->map[x])
	{
		y = 0;
		while (center->data->map[x][y])
		{
			if (center->data->map[x][y] == 'N' || center->data->map[x][y] == 'S'
				|| center->data->map[x][y] == 'E'
				|| center->data->map[x][y] == 'W')
			{
				center->player_start_xy[0] = x;
				center->player_start_xy[1] = y;
				return ;
			}
			y++;
		}
		x++;
	}
}
