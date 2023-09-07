/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_shortcut_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 19:04:13 by cormiere          #+#    #+#             */
/*   Updated: 2023/09/07 15:12:53 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_first_c(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (i);
		i++;
	}
	return (i);
}

int	ft_is_from_map(char **map, int i, int j)
{
	if (((map[i][j] == '1' || map[i][j] == '0')
		&& (map[i][ft_first_c(map[i])] != 'F'\
		&& map[i][ft_first_c(map[i])] != 'C')) || (map[i][j] == 'N'\
		&& map[i][j + 1] != 'O'
		&& (!ft_isalpha(map[i][j + 1]) && (j > 0 && !ft_isalpha(map[i][j - 1]))))
		|| (map[i][j] == 'S' && map[i][j + 1] != 'O'
		&& (!ft_isalpha(map[i][j + 1]) && (j > 0 && !ft_isalpha(map[i][j - 1]))))
		|| (map[i][j] == 'W' && map[i][j + 1] != 'E'
		&& (!ft_isalpha(map[i][j + 1]) && (j > 0 && !ft_isalpha(map[i][j - 1]))))
		|| (map[i][j] == 'E'\
		&& map[i][j + 1] != 'A' && map[i][j - 1] != 'W'
		&& (!ft_isalpha(map[i][j + 1]) && (j > 0 && !ft_isalpha(map[i][j - 1])))))
		return (1);
	return (0);
}

static int	ft_is_col_empty(char **map, int col)
{
	int	i;

	i = 0;
	if (!map || !map[0])
		return (2);
	while (map[i][col])
	{
		if ((map[i]) && map[i][col] != ' ' && map[i][col] != '\t'\
			&& map[i][col] != '\n')
			return (0);
		i++;
		if (!map[i])
			return (1);
	}
	return (1);
}

static void	ft_update_map(char **map, int end_line, int end_col)
{
	int	i;

	i = 0;
	free(map[end_line]);
	map[end_line] = NULL;
	while (map[i])
	{
		map[i][end_col] = '\0';
		i++;
	}
}

int	ft_check_vertical_multiple_map(char **map, const int len, int end_line,
	int j)
{
	int	i;

	if (!map || !map[0])
		return (1);
	while (++j < len)
	{
		if (!ft_is_col_empty(map, j))
		{
			while (!ft_is_col_empty(map, j))
				j++;
			i = j;
			while (map[0][i] && ft_is_col_empty(map, i) == 1)
				i++;
			if (map[0][i] && !ft_is_col_empty(map, i))
			{
				ft_free_sp_array(map);
				return (1);
			}
			else
				break ;
		}
	}
	ft_update_map(map, end_line, j);
	return (0);
}
