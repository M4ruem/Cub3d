/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arrays_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:55:48 by cormiere          #+#    #+#             */
/*   Updated: 2023/09/13 18:32:58 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frees_bonus.h"

void	ft_free_multiple_array(char **ar1, char **ar2)
{
	int	i;

	i = -1;
	if (ar1)
	{
		while (ar1[++i])
		{
			free(ar1[i]);
			ar1[i] = NULL;
		}
		free(ar1);
		ar1 = NULL;
	}
	if (ar2)
	{
		i = -1;
		while (ar2[++i])
		{
			free(ar2[i]);
			ar2[i] = NULL;
		}
		free(ar2);
		ar2 = NULL;
	}
}

void	ft_free_texture_paths(char **array)
{
	int	i;

	i = -1;
	if (array)
	{
		while (++i < 4)
		{
			if (array[i])
			{
				free(array[i]);
				array[i] = NULL;
			}
		}
	}
	return ;
}

void	ft_free_sp_array(char **array)
{
	int	i;

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
