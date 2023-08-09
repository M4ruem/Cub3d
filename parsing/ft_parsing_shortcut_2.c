/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_shortcut_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:50:21 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/09 21:47:15 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**ft_arraydup(char **map, int index, int i)
{
	char		**new_map;
	int			j;
	const int	len = ft_array_len(map);

	j = -1;
	new_map = ft_calloc(sizeof(char *), len - index + 1);
	if (!new_map)
		ft_free_multiple_array(NULL, map, NULL);
	if (!new_map)
		return (NULL);
	while (map[++i] && i <= index)
	{
		new_map[++j] = ft_strdup(map[i]);
		if (!new_map[j])
		{
			ft_free_multiple_array(new_map, map, NULL);
			return (NULL);
		}
	}
	return (new_map);
}
