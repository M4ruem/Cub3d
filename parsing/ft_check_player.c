/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 19:40:17 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/09 17:25:52 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_is_player_surrounded(char **map, int i, int j)
{
	if ((i > 0 && (map[i - 1][j] == '0' || map[i - 1][j] == '1'))
		&& (map[i + 1][j] && (map[i + 1][j] == '0' || map[i + 1][j] == '1'))
		&& (j > 0 && (map[i][j - 1] == '0' || map[i][j - 1] == '1'))
		&& (map[i][j + 1] && (map[i][j + 1] == '0' || map[i][j + 1] == '1')))
		return (1);
	return (0);
}

int	ft_check_player(char **map, int i, int j)
{
	int	player;
	int	status;

	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] && (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E'))
			{
				player += 1;
				if (player > 1)
					return (TOO_MANY_PEOPLE_AAAAAH);
				if (ft_is_player_surrounded(map, i, j))
					status = PLAYER_OKAY;
				else
					status = PLAYER_KAYO;
			}
		}
	}
	if (player == 0)
		return (PLAYER_IS_BRINGING_MILK);
	return (status);
}
