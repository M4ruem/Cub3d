/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:23:11 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/08 20:07:53 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_map_analysis(char **map)
{
	int error;

	error = ft_check_horizontal_map_border(map, 0, 0);
	if (error != LINES_OK)
		return (0);
	error = ft_check_vertical_map_border(map, 0, 0);
	if (error != COL_OK)
		return (0);
	error = ft_check_player(map);
	if (error != PLAYER_OKAY)
		return (0);
	return (1);
}
