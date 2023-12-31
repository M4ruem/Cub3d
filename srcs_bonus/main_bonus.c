/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:27:58 by cormiere          #+#    #+#             */
/*   Updated: 2023/09/13 18:35:09 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_printf_files_errors(int error_key, char *file)
{
	if (error_key != FILE_RDONLY && error_key != FILE_RDWR
		&& error_key != FILE_RDWRX && error_key != FILE_KO
		&& error_key != FILE_NO_PERMS)
	{
		ft_printf_fd(2, "Error\n%s%s%s\n", "PERMISSION DENIED: ",
			file, " IS UNREADABLE");
	}
	if (error_key == FILE_NO_PERMS)
	{
		ft_printf_fd(2, "Error\n%s %s\n",
			"PERMISSION DENIED: NO PERMISSIONS ON:", file);
	}
	if (error_key == FILE_KO)
	{
		ft_printf_fd(2, "Error\n%s%s\n", "NO SUCH FILE OR DIRECTORY: ",
			file);
	}
}

void	ft_printf_map_error(int error_key)
{
	if (error_key == HOLE_IN_LINE)
		ft_printf_fd(2, "Error\n%s\n", "HOLE IN A LINE OF THE MAP");
	if (error_key == INCOMPLETE_LINE)
		ft_printf_fd(2, "Error\n%s\n", "INCOMPLETE LINE IN THE MAP");
	if (error_key == BAD_LINE)
		ft_printf_fd(2, "Error\n%s\n", "LINE WITHOUT BORDERS IN THE MAP");
	if (error_key == HOLE_IN_COL)
		ft_printf_fd(2, "Error\n%s\n", "HOLE IN A COLUMN OF THE MAP");
	if (error_key == INCOMPLETE_COL)
		ft_printf_fd(2, "Error\n%s\n", "INCOMPLETE COLUMN OF THE MAP");
	if (error_key == BAD_COL)
		ft_printf_fd(2, "Error\n%s\n", "COLUMN WITHOUT BORDERS IN THE MAP");
	if (error_key == PLAYER_IS_BRINGING_MILK)
		ft_printf_fd(2, "Error\n%s\n", "NO PLAYER ON THE MAP");
	if (error_key == PLAYER_KAYO)
		ft_printf_fd(2, "Error\n%s\n",
			"THE PLAYER IS NOT TOTALLY INSIDE OR IS LITTERALY OUTSIDE THE MAP");
	if (error_key == TOO_MANY_PEOPLE_AAAAAH)
		ft_printf_fd(2, "Error\n%s\n",
			"MORE THAN ONE PLAYER ON THE MAP");
	if (error_key == INTRUDER_CHARACTER)
		ft_printf_fd(2, "Error\n%s\n", "ABNORMAL CHARACTER ON THE MAP");
}

int	main(int ac, char **av)
{
	t_akinator	*data;
	int			error;

	if (ac != 2)
	{
		if (ac < 2)
			ft_printf_fd(2, "Error\n%s\n", "TOO FEW ARGUMENTS");
		else
			ft_printf_fd(2, "Error\n%s\n", "TOO MANY ARGUMENTS");
		return (0);
	}
	data = ft_launch_parsing(av, 0);
	if (!data)
		return (1);
	error = ft_check_if_textures_works(data);
	if (!error)
		return (1);
	ft_launch_raycasting(data);
	return (0);
}
