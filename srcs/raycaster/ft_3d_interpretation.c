/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3d_interpretation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 13:54:15 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/28 14:41:08 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

void	ft_ceiling_making(t_gpt *center)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (x < WIDTH)
	{
		while (y < HEIGHT / 2)
		{
			mlx_put_pixel(center->fov_img, x, y, 0xFF4400FF);
			y++;
		}
		x++;
	}
}

void	ft_floor_making(t_gpt *center)
{
	int	x;
	int	y;
	
	x = 0;
	y = HEIGHT / 2;
	while (x < WIDTH)
	{
		while (y < HEIGHT)
		{
			mlx_put_pixel(center->fov_img, x, y, 0x00FF00FF);
			y++;
		}
		x++;
	}
}

// void	ft_wall_making(t_gpt *center)
// {

// }

void	ft_3d_making(t_gpt *center)
{
	ft_floor_making(center);
	ft_ceiling_making(center);
}