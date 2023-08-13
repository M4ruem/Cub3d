/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coloring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:30:06 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/13 18:22:54 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycaster_header.h"

void	ft_set_color(t_gpt *center)
{
	int	x;
	int	y;

	x = 0;
	while (x < (int)center->player->width)
	{
		y = 0;
		while (y < (int)center->player->height)
		{
			mlx_put_pixel(center, x, y, 0xFF0000FF);
			y++;
		}
		x++;
	}
}

/*
void ft_set_color2(void* arg)
{
	(void)arg;
	int x;
	int y;

	x = 0;
	while (x < (int)pouet->width)
	{
		y = 0;
		while (y < (int)pouet->height)
		{
			mlx_put_pixel(pouet, x, y, 0x000000FF);
			y++;
		}
		x++;
	}
}*/
