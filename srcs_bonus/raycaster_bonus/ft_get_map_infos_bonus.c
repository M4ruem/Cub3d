/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_infos_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:32:33 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/13 18:34:24 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header_bonus.h"

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
			if (center->data->map[x][y] == 'N'
				|| center->data->map[x][y] == 'S'
				|| center->data->map[x][y] == 'E'
				|| center->data->map[x][y] == 'W')
			{
				center->player_start_sens = center->data->map[x][y];
				center->player.x = center->size * y + (center->size / 2);
				center->player.y = center->size * x + (center->size / 2);
				return ;
			}
			y++;
		}
		x++;
	}
}
