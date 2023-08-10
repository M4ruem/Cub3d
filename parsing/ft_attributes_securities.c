/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attributes_securities.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:46:54 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/10 18:14:01 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_attrib_missing(t_akinator *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (ft_is_line_empty(data->texture_paths[i]))
		{
			ft_printf_fd(2, "MISSING TEXTURES\n");
			return (1);
		}
	}
	if (data->Floor_rgb[0] == -1 || data->Floor_rgb[1] == -1
		|| data->Floor_rgb[2] == -1)
	{
		ft_printf_fd(2, "MISSING COLORS\n");
		return (1);
	}
	if (data->Ceiling_rgb[0] == -1 || data->Ceiling_rgb[1] == -1
		|| data->Ceiling_rgb[2] == -1)
	{
		ft_printf_fd(2, "MISSING COLORS\n");
		return (1);
	}
	return (0);
}
