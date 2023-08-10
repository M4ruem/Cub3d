/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 15:01:51 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/10 15:03:03 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, int size)
{
	int		pos;
	char	*cpy;

	pos = 0;
	cpy = malloc(sizeof(char) * size + 1);
	if (cpy == 0)
		return (NULL);
	while (src[pos] && pos < size)
	{
		cpy[pos] = src[pos];
		pos++;
	}
	cpy[pos] = 0;
	return (cpy);
}

char	*ft_strdup_fill(char *src, int end)
{
	int		pos;
	char	*cpy;

	pos = 0;
	cpy = malloc(sizeof(char) * end + 1);
	if (cpy == 0)
		return (NULL);
	while (src[pos] && pos < end)
	{
		cpy[pos] = src[pos];
		pos++;
	}
	if (pos < end)
	{
		while (pos < end)
		{
			cpy[pos] = ' ';
			pos++;
		}
	}
	cpy[pos] = 0;
	return (cpy);
}
