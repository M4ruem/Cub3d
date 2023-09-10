/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:48:10 by cormiere          #+#    #+#             */
/*   Updated: 2023/09/10 16:11:06 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frees.h"

void	ft_free_data(t_akinator *data)
{
	ft_free_texture_paths(data->texture_paths);
	ft_free_multiple_array(data->map, NULL);
	free(data);
	data = NULL;
	return ;
}

void	ft_free_center(t_gpt *center)
{
	mlx_delete_texture(center->textures_tab.east);
	mlx_delete_texture(center->textures_tab.west);
	mlx_delete_texture(center->textures_tab.north);
	mlx_delete_texture(center->textures_tab.south);
	ft_free_data(center->data);
	free(center);
}
