/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:48:10 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/09 17:49:59 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_data(t_akinator *data)
{
	ft_free_sp_array(data->texture_paths);
	ft_free_multiple_array(data->map, NULL, NULL);
	free(data);
	return ;
}
