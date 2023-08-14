/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_inside_row_col.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:26:55 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/14 14:11:55 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_inside_line(char *line, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		if (line[i] == ' ' || line[i] == '\t')
		{
			if (!(line[i - 1] == '1'))
				return (0);
			while (line[i] == ' ' || line[i] == '\t')
				i++;
			if (!(line[i] && line[i] == '1'))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_inside_col(char **map, int col, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		if (map[i][col] == ' ' || map[i][col] == '\t')
		{
			if (!(map[i - 1][col] == '1'))
				return (0);
			while (map[i][col] == ' ' || map[i][col] == '\t')
				i++;
			if (!(map[i][col] && map[i][col] == '1'))
				return (0);
		}
		i++;
	}
	return (1);
}
