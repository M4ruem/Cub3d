/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:35:14 by cormiere          #+#    #+#             */
/*   Updated: 2023/09/13 18:49:09 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

static int	ft_check_file_access(char *str)
{
	if (access(str, R_OK) != -1)
	{
		if (access(str, W_OK) != -1)
		{
			if (access(str, X_OK) != -1)
				return (FILE_RDWRX);
			return (FILE_RDWR);
		}
		else if (access(str, X_OK) != -1)
			return (FILE_RDX);
		return (FILE_RDONLY);
	}
	else if (access(str, W_OK) != -1)
	{
		if (access(str, X_OK) != -1)
			return (FILE_WRX);
		return (FILE_WRONLY);
	}
	else if (access(str, X_OK) != -1)
		return (FILE_XONLY);
	return (FILE_NO_PERMS);
}

int	ft_check_access(char *str)
{
	int	test;

	test = open(str, __O_DIRECTORY, 777);
	if (test != -1)
	{
		close(test);
		return (IS_A_DIREC);
	}
	if (access(str, F_OK) != -1)
		return (ft_check_file_access(str));
	return (FILE_KO);
}

int	ft_check_args(char **av)
{
	int	perms;
	int	i;

	i = ft_strlen(av[1]);
	if (!av[1])
		return (0);
	while (av[1][i] != '.' && i > 0)
		i--;
	if ((av[1][i] != '.') || (av[1][i] == '.' && !av[1][i + 1]) \
		|| ((ft_strcmp(&av[1][i], ".cub") && ft_strlen(av[1]) >= 4)) \
		|| (!ft_strcmp(&av[1][i], ".cub") && ft_strlen(av[1]) <= 4) \
		|| (!ft_strcmp(&av[1][i], ".cub") && ft_strlen(av[1]) >= 5 \
		&& av[1][i - 1] == '/'))
	{
		ft_printf_fd(2, "Error\n%s\n", "WRONG FORMAT");
		return (0);
	}
	perms = ft_check_access(av[1]);
	if (perms != FILE_RDONLY && perms != FILE_RDWR && perms != FILE_RDWRX)
	{
		ft_printf_files_errors(perms, av[1]);
		return (0);
	}
	return (1);
}
