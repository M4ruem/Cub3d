/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_row_and_col.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:10:29 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/09 18:35:31 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_get_eol(char *line, int i)
{
	int	last_one;

	last_one = -1;
	while (line[i])
	{
		if (line[i] && line[i] == '1')
			last_one = i;
		i++;
	}
	return (last_one);
}

int	ft_check_horizontal_map_border(char **map, int i, int j)
{
	int	k;

	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			j++;
		if (map[i][j] && map[i][j] == '1')
		{
			k = ft_get_eol(map[i], j + 1);
			if (k > 0 && map[i][k] && map[i][k] == '1')
			{
				if (!ft_check_inside_line(map[i], j, k))
					return (HOLE_IN_LINE);
				i++;
			}
			else
				return (INCOMPLETE_LINE);
		}
		else
			return (BAD_LINE);
	}
	return (LINES_OK);
}

static int	ft_get_eoc(char **map, int col, int i)
{
	int	last_one;

	last_one = -1;
	while (map[i][col])
	{
		if (map[i][col] && map[i][col] == '1')
			last_one = i;
		i++;
	}
	return (last_one);
}

int	ft_check_vertical_map_border(char **map, int i, int j)
{
	int	k;

	while (map[i][j])
	{
		i = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			i++;
		if (map[i][j] && map[i][j] == '1')
		{
			k = ft_get_eoc(map, j, i + 1);
			if (k > 0 && map[k][j] && map[k][j] == '1')
			{
				if (!ft_check_inside_col(map, j, i, k))
					return (HOLE_IN_COL);
				i++;
			}
			else
				return (INCOMPLETE_COL);
		}
		else
			return (BAD_COL);
	}
	return (COL_OK);
}
