/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:27:58 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/08 17:11:21 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		if (ac < 2)
			printf("%s\n" , "too few arguments"); //a changer
		else
			printf("%s\n" , "too many arguments"); //a changer
		return 0;
	}
	ft_launch_parsing(av);
	return (0);
}
