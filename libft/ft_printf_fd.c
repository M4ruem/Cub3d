/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:26:39 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/01/18 16:54:08 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_which_format_fd(char format, va_list args, int fd)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_prt_char_fd(va_arg(args, int), fd);
	if (format == 's')
		len += ft_prt_str_fd(va_arg(args, char *), fd);
	if (format == 'p')
		len += ft_prt_ptr_fd(va_arg(args, void *), fd);
	if (format == 'd' || format == 'i')
		len += ft_prt_int_fd(va_arg(args, int), fd);
	if (format == 'u')
		len += ft_prt_uns_fd(va_arg(args, unsigned), fd);
	if (format == 'x' || format == 'X')
		len += ft_prt_hex_fd(va_arg(args, int), format, fd);
	if (format == '%')
		len += ft_prt_char_fd('%', fd);
	return (len);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list	params;
	int		i;
	int		len;

	len = 0;
	i = 0;
	va_start(params, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_which_format_fd(str[++i], params, fd);
		}
		else
			len += ft_prt_char_fd(str[i], fd);
		i++;
	}
	va_end(params);
	return (len);
}
