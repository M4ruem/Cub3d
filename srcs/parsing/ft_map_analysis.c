/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:23:11 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/11 18:21:19 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_map_analysis(char **map)
{
	int error;

	error = ft_check_horizontal_map_border(map, 0, 0);
	if (error != LINES_OK)
		ft_printf_map_error(error);
	if (error != LINES_OK)
		return (0);
	error = ft_check_vertical_map_border(map, 0, -1);
	if (error != COL_OK)
		ft_printf_map_error(error);
	if (error != COL_OK)
		return (0);
	error = ft_check_player(map, -1, -1, 0);
	if (error != PLAYER_OKAY)
	{
		ft_printf_map_error(error);
		return (0);
	}
	return (1);
}
