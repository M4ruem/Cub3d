/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:41:11 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/08 21:19:01 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_isnt_from_map(char c, char *last_char)
{
	if (!(c != ' ' && c != '\t' && c != 'N' && c != 'W'
			&& c != 'E' && c != 'S'))
		*last_char = c;
	return ;
}

int	ft_where_to_cut(char **map)
{
	int		i;
	int		j;
	char	last_char;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_isnt_from_map(map[i][j], &last_char);
			if (map[i][j] == '1' || map[i][j] == '0' || map[i][j] == 'N'
				|| map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
				if (!last_char)
					return (i);
			j++;
		}
		last_char = NULL;
		i++;
	}
}

static char	**ft_ajust_map(char **map, int index)
{
	char	**new_map;
	const	int len = ft_array_len(map);
	int		i;
	int		j;

	j = 0;
	i = index;
	new_map = ft_calloc(sizeof(char *), len -  index);
	if (!new_map)
		return (NULL);
	while (map[i])
	{
		new_map[j] = ft_self_made_strcpy(map[i]);
		if (!new_map[j])
		{
			ft_free_multiple_array(new_map, map, NULL);
			return (NULL);
		}
		j++;
		i++;
	}
	ft_free_multiple_array(NULL, NULL, map);
	return (new_map);
}

char **ft_split_map_attrib(char **map)
{
	char	**attributes;
	const int index = ft_where_to_cut(map);
	int	i;

	i = 0;
	attributes = ft_calloc(sizeof(char *), index);
	if (!attributes)
		return (NULL);
	while (i < index)
	{
		attributes[i] = ft_self_made_strcpy(map[i]);
		if (!attributes[i])
		{
			ft_free_multiple_array(attributes, map, NULL);
			return (NULL);
		}
		i++;
	}
	map = ft_ajust_map(map, index);
	if (!map)
	{
		ft_free_multiple_array(attributes, NULL, NULL);
		return (NULL);
	}
	return (attributes);
}

char **ft_launch_parsing(char **av)
{
	int		test_error;
	char	**map;
	char	**attributes;

	test_error = ft_check_args(av);
	if (!test_error)
		return (NULL);
	map = ft_check_file_content(av[1]);
	attributes = ft_split_map_attrib(map);
	if (!attributes)
		return (NULL);
	test_error = ft_map_analysis(map);
	if (!test_error)
	{
		ft_free_multiple_array(map, NULL, NULL);
		return (NULL);
	}
	return (/*struct*/);
}
