/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_char_str_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:03:55 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/01/18 16:11:30 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_prt_char_fd(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_prt_str_fd(char *str, int fd)
{
	if (!str)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	else
		ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}
