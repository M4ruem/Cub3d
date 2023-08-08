/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prt_hex_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 18:03:57 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/01/18 16:13:16 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_putnbr_hex_fd(size_t nbr, char *base, int fd)
{
	char	b;
	size_t	len;

	len = ft_strlen(base);
	if (nbr >= len)
		ft_putnbr_hex_fd(nbr / len, base, fd);
	b = base[nbr % len];
	write(fd, &b, 1);
}

static int	ft_prt_hex_ptr_fd(size_t n, int fd)
{
	char	*base;
	int		i;
	size_t	nb;

	nb = n;
	i = 1;
	base = "0123456789abcdef";
	while (nb >= 16)
	{
		nb /= 16;
		i += 1;
	}
	ft_putnbr_hex_fd(n, base, fd);
	return (i);
}

static void	ft_putnbr_base_fd(unsigned int nbr, char *base, int fd)
{
	char			b;
	unsigned int	len;

	len = ft_strlen(base);
	if (nbr >= len)
		ft_putnbr_base_fd(nbr / len, base, fd);
	b = base[nbr % len];
	write(fd, &b, 1);
}

int	ft_prt_hex_fd(unsigned int n, char c, int fd)
{
	char			*base;
	int				i;
	unsigned int	nb;

	nb = n;
	i = 1;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	while (nb >= 16)
	{
		nb /= 16;
		i += 1;
	}
	ft_putnbr_base_fd(n, base, fd);
	return (i);
}

int	ft_prt_ptr_fd(void *ptr, int fd)
{
	int		len;
	size_t	asterisk;

	len = 0;
	asterisk = (size_t)ptr;
	if (!ptr)
		len += ft_prt_str_fd("(nil)", fd);
	else
	{
		len += ft_prt_str_fd("0x", fd);
		len += ft_prt_hex_ptr_fd(asterisk, fd);
	}
	return (len);
}
