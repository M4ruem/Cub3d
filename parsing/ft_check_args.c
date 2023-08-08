/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:35:14 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/08 17:00:23 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_strcmp(char *s1, char *s2)
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

static int	ft_check_access(char *str)
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
	int	test_perms;
	int	i;

	i = 0;
	if (!av[1])
		return (0);
	while (av[1][i] != '.')
		i++;
	if ((ft_strcmp(&av[1][i], ".cub")))
	{
		printf("%s\n", "Wrong format");
		return (0);
	}
	test_perms = ft_check_access(av[1]);
	if (test_perms != FILE_RDONLY && test_perms != FILE_RDWR
		&& test_perms != FILE_RDWRX)
		return (0);
	return (1);
}
