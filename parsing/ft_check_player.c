/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:40:17 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/08 20:06:11 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] && (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E'))
			{
				if ((map[i - 1][j] == '0' || map[i - 1][j] == '1')
					&& (map[i + 1][j] == '0' || map[i + 1][j] == '1')
					&& (map[i][j - 1] == '0' || map[i][j - 1] == '1')
					&& (map[i][j + 1] == '0' || map[i][j + 1] == '1'))
					return (PLAYER_OKAY);
				else
					return (PLAYER_KAYO);
			}
		}
	}
	return (PLAYER_IS_BRINGING_MILK);
}
