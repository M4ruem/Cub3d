/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 14:03:41 by jdelsol-          #+#    #+#             */
/*   Updated: 2022/12/14 11:12:52 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char *src)
{
	int	pos;
	int	append;

	append = 0;
	pos = 0;
	while (dest[append])
		append++;
	while (src[pos])
	{
		dest[append] = src[pos];
		pos++;
		append++;
	}
	dest[append] = '\0';
	return (dest);
}

char	*ft_join(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*res;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!s1 || !s2)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (res == 0)
		return (NULL);
	res[0] = 0;
	res = ft_strcat(res, str1);
	res = ft_strcat(res, str2);
	free(str1);
	return (res);
}
