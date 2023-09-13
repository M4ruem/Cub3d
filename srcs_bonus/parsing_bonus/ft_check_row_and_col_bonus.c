/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_row_and_col_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:10:29 by cormiere          #+#    #+#             */
/*   Updated: 2023/09/13 18:33:30 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	ft_map_characters(char c)
{
	if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	ft_get_eol(char *line, int i)
{
	int	last_one;

	last_one = i - 1;
	while (line[i])
	{
		if (line[i] && (line[i] == '1' || line[i] == '0' || line[i] == 'N'\
			|| line[i] == 'E' || line[i] == 'W' || line[i] == 'S'))
			last_one = i;
		else if (line[i] && (line[i] != ' ' && line[i] != '\t'))
			return (i);
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
			if (map[i][k] && map[i][k] == '1')
			{
				if (!ft_check_inside_line(map[i], j, k))
					return (HOLE_IN_LINE);
				i++;
			}
			else if (map[i][k] && !ft_map_characters(map[i][k]))
				return (INTRUDER_CHARACTER);
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

	last_one = i - 1;
	if (!map[i])
		return (last_one);
	while (map[i][col])
	{
		if (map[i][col] && (map[i][col] == '1' || map[i][col] == '0'\
			|| map[i][col] == 'N' || map[i][col] == 'E' || map[i][col] == 'W'\
			|| map[i][col] == 'S'))
			last_one = i;
		i++;
		if (!map[i])
			break ;
	}
	return (last_one);
}

int	ft_check_vertical_map_border(char **map, int i, int j)
{
	int	k;

	while (map[i][++j])
	{
		i = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			i++;
		if (map[i][j] && map[i][j] == '1')
		{
			k = ft_get_eoc(map, j, i + 1);
			if (map[k][j] && map[k][j] == '1')
			{
				if (!ft_check_inside_col(map, j, i, k))
					return (HOLE_IN_COL);
			}
			else
				return (INCOMPLETE_COL);
		}
		else
			return (BAD_COL);
	}
	return (COL_OK);
}
