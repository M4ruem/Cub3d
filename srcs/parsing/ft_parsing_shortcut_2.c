/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_shortcut_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:50:21 by cormiere          #+#    #+#             */
/*   Updated: 2023/09/09 18:10:08 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**ft_arraydup(char **map, int index, int i)
{
	char		**new_map;
	int			j;
	const int	len = ft_array_len(map);

	j = -1;
	new_map = ft_calloc(sizeof(char *), len + 1);
	if (!new_map)
		ft_free_multiple_array(NULL, map);
	if (!new_map)
		return (NULL);
	while (map[++i] && i <= index)
	{
		new_map[++j] = ft_strdup(map[i]);
		if (!new_map[j])
		{
			ft_free_multiple_array(new_map, map);
			return (NULL);
		}
	}
	new_map[i] = NULL;
	return (new_map);
}

char	**ft_rarraydup(char **map, int index, int i)
{
	char		**new_map;
	int			j;
	const int	len = ft_array_len(map);

	j = -1;
	new_map = ft_calloc(sizeof(char *), len - index + 1);
	if (!new_map)
		ft_free_multiple_array(NULL, map);
	if (!new_map)
		return (NULL);
	while (map[++i])
	{
		new_map[++j] = ft_strdup(map[i]);
		if (!new_map[j])
		{
			ft_free_multiple_array(new_map, map);
			return (NULL);
		}
	}
	return (new_map);
}

int	ft_max_line(char **map)
{
	int	i;
	int	max;

	max = 0;
	i = 0;
	while (map[i])
	{
		if (max < (int)ft_strlen(map[i]))
			max = (int)ft_strlen(map[i]);
		i++;
	}
	return (max);
}

int	ft_is_line_empty(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (2);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_multiple_map(char **map, const int len, int i, int j)
{
	if (!map || !map[0])
		return (1);
	while (++i < len)
	{
		if (!ft_is_line_empty(map[i]))
		{
			while (!ft_is_line_empty(map[i]))
				i++;
			j = i;
			while (ft_is_line_empty(map[j]) == 1)
				j++;
			if (map[j] && !ft_is_line_empty(map[j]))
			{
				ft_free_sp_array(map);
				return (1);
			}
			else
				break ;
		}
	}
	if (ft_check_vertical_multiple_map(map, ft_max_line(map), i, -1))
		return (1);
	return (0);
}
