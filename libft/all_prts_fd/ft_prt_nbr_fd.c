/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_nbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:04:00 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/01/18 16:53:03 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_cut_fd(unsigned long long nb, int fd)
{
	unsigned long long	number;
	char				result;

	if (nb >= 10)
	{
		number = nb / 10;
		ft_cut_fd(number, fd);
	}
	result = nb % 10 + '0';
	write(fd, &result, 1);
}

static void	ft_fd_putnbr(long long nb, int fd)
{
	if (nb == 9223372036854775807)
		ft_prt_str_fd("9223372036854775807", fd);
	else if (nb == -9223372036854775807)
		ft_prt_str_fd("-9223372036854775807", fd);
	else if (nb >= 0)
		ft_cut_fd(nb, fd);
	else
	{
		write(fd, "-", 1);
		ft_cut_fd(-nb, fd);
	}
}

int	ft_prt_int_fd(int i, int fd)
{
	int	j;

	j = 1;
	if (i < 0)
		j++;
	ft_fd_putnbr(i, fd);
	while (i >= 10 || i <= -10)
	{
		i /= 10;
		j++;
	}
	return (j);
}

int	ft_prt_uns_fd(unsigned int i, int fd)
{
	int	j;

	j = 1;
	ft_cut_fd(i, fd);
	while (i >= 10)
	{
		i /= 10;
		j++;
	}
	return (j);
}
