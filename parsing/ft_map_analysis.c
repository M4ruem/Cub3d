/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:23:11 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/10 13:41:36 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_map_analysis(char **map)
{
	int error;

	error = ft_check_horizontal_map_border(map, 0, 0);
	if (error != LINES_OK)
		ft_printf_fd(2, "HORIZONTAL LINES ERROR\n");
	if (error != LINES_OK)
		return (0);
	error = ft_check_vertical_map_border(map, 0, -1);
	if (error != COL_OK)
		ft_printf_fd(2, "VERTICAL LINES ERROR\n");
	if (error != COL_OK)
		return (0);
	error = ft_check_player(map, -1, -1);
	if (error != PLAYER_OKAY)
	{
		if (error == PLAYER_IS_BRINGING_MILK)
			ft_printf_fd(2, "NO PLAYER ON THE MAP\n");
		else if (error == PLAYER_KAYO)
			ft_printf_fd(2, "PLAYER ERROR\n");
		else if (error == TOO_MANY_PEOPLE_AAAAAH)
			ft_printf_fd(2, "TOO MANY PLAYER SYMBOLS...\n");
		return (0);
	}
	return (1);
}
