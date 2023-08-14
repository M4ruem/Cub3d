/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:41:11 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/14 14:05:18 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	ft_isnt_from_map(char c)
{
	if ((c != ' ' && c != '\t' && c != 'N' && c != 'W'
			&& c != 'E' && c != 'S' && c != '1' && c != '0'))
		return (c);
	return (0);
}

static int	ft_cut(char **map, char last_char, int i, int j)
{
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			last_char = ft_isnt_from_map(map[i][j]);
			if (ft_is_from_map(map, i, j))
			{
				if (last_char == 0)
				{
					if (i == 0)
						ft_printf_fd(2, "Error\nEMPTY ATTRIBUTES\n");
					if (i == 0)
						return (0);
					return (i - 1);
				}
			}
		}
		last_char = 0;
		if (!map[i + 1])
			break ;
	}
	return (i);
}

static int	ft_ajust_map(char **map, int index)
{
	int			i;
	int			j;
	const char	**tmp = (const char **)ft_rarraydup(map, index, index);

	j = -1;
	i = -1;
	ft_free_sp_array(map);
	while (tmp[++i])
	{
		map[++j] = ft_strdup_fill((char *)tmp[i], ft_max_line((char **)tmp));
		if (!map[j])
		{
			ft_free_multiple_array(map, (char **)tmp, NULL);
			return (0);
		}
	}
	ft_free_multiple_array((char **)tmp, NULL, NULL);
	if (ft_is_empty_file(map)
		|| ft_check_multiple_map(map, ft_array_len(map), -1, 0))
	{
		ft_printf_fd(2, "Error\nEMPTY MAP OR MULTIPLE MAP\n");
		free(map);
		return (0);
	}
	return (1);
}

static char	**ft_split_map_attrib(char **map)
{
	const int	index = ft_cut(map, 0, -1, -1);
	int			error;
	char		**attributes;

	if (!index)
		ft_free_multiple_array(map, NULL, NULL);
	if (!index)
		return (NULL);
	attributes = ft_arraydup(map, index, -1);
	if (!attributes)
		return (NULL);
	error = ft_ajust_map(map, index);
	if (!error)
		ft_free_multiple_array(attributes, NULL, NULL);
	if (!error)
		return (NULL);
	return (attributes);
}

t_akinator	*ft_launch_parsing(char **av, int error)
{
	char		**map;
	char		**attributes;
	t_akinator	*data;

	error = ft_check_args(av);
	if (!error)
		return (NULL);
	map = ft_check_file_content(av[1], 0, NULL, NULL);
	if (!map)
		return (NULL);
	attributes = ft_split_map_attrib(map);
	if (!attributes)
		return (NULL);
	error = ft_map_analysis(map);
	if (!error)
		ft_free_multiple_array(map, attributes, NULL);
	if (!error)
		return (NULL);
	data = ft_set_up_akinator(attributes, map, -1);
	if (!data)
		return (NULL);
	return (data);
}
