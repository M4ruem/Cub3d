/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attributes_securities.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:46:54 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/11 18:26:19 by jdelsol-         ###   ########.fr       */
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
			ft_printf_fd(2, "Error\nMISSING TEXTURES\n");
			return (1);
		}
	}
	if (data->Floor_rgb[0] == -1 || data->Floor_rgb[1] == -1
		|| data->Floor_rgb[2] == -1)
	{
		ft_printf_fd(2, "Error\nMISSING COLORS\n");
		return (1);
	}
	if (data->Ceiling_rgb[0] == -1 || data->Ceiling_rgb[1] == -1
		|| data->Ceiling_rgb[2] == -1)
	{
		ft_printf_fd(2, "Error\nMISSING COLORS\n");
		return (1);
	}
	return (0);
}
