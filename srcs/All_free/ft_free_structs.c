/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_structs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:48:10 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/14 14:16:54 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frees.h"

void	ft_free_data(t_akinator *data)
{
	ft_free_sp_array(data->texture_paths);
	ft_free_multiple_array(data->map, NULL, NULL);
	free(data);
	return ;
}

void	ft_free_center(t_gpt *center)
{
	ft_free_data(center->data);
	free(center);
}
