/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:13:24 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/09 15:18:51 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_akinator *ft_init_struct(int map_len)
{
	t_akinator *data;
	int			i;

	i = -1;
	data = ft_calloc(sizeof(t_akinator), 1);
	if (!data)
		return (NULL);
	data->map = ft_calloc(sizeof(char *), map_len);
	if (!data->map)
	{
		free(data);
		return (NULL);
	}
	while (++i < 4)
		data->texture_paths[i] = NULL;
	i = -1;
	while (++i < 3)
	{
		data->Ceiling_rgb[i] = 0;
		data->Floor_rgb[i] = 0;
	}
	return (data);
}
