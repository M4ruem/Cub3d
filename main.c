/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:27:58 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/10 18:05:49 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_akinator *data;
	int	error;

	if (ac != 2)
	{
		if (ac < 2)
			ft_printf_fd(2, "%s\n" , "too few arguments\n"); //a changer
		else
			ft_printf_fd(2, "%s\n" , "too many arguments\n"); //a changer
		return 0;
	}
	data = ft_launch_parsing(av, 0);
	if (!data)
		return (1);
	error = ft_check_texture_paths(data);
	if (!error)
	{
		ft_printf_fd(2, "WRONG TEXTURE PATHS\n");
		return (1);
	}
	//func
	ft_free_data(data);
	return (0);
}
