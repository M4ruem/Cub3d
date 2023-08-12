/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arrays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:55:48 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/11 19:18:57 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_multiple_array(char **ar1, char **ar2, char **ar3)
{
	int i;

	i = -1;
	if (ar1)
	{
		while (ar1[++i])
			free(ar1[i]);
		free(ar1);
	}
	if (ar2)
	{
		i = -1;
		while (ar2[++i])
			free(ar2[i]);
		free(ar2);
	}
	if (ar3)
	{
		i = -1;
		while (ar3[++i])
			free(ar3[i]);
		free(ar3);
	}
}

void	ft_free_sp_array(char **array)
{
	int i;

	i = -1;
	if (array)
	{
		while (array[++i])
		{
			free(array[i]);
			array[i] = NULL;
		}
	}
	return ;
}
