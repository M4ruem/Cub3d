/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_mouvement_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:12:17 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/13 18:34:46 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header_bonus.h"

void	ft_mouse_mouvement(t_gpt *center)
{
	int32_t			xy[2];
	int32_t			dist;

	mlx_get_mouse_pos(center->mlx, &xy[0], &xy[1]);
	if ((xy[1] > 100 && xy[1] < HEIGHT - 100))
	{
		dist = fabs((double)(xy[0] - DEMI_WIDTH));
		if (xy[0] < DEMI_WIDTH)
			center->player.angle -= MOUSE_SENSI * dist;
		else if (xy[0] > DEMI_WIDTH)
			center->player.angle += MOUSE_SENSI * dist;
		mlx_set_mouse_pos(center->mlx, DEMI_WIDTH, DEMI_HEIGHT);
	}
}
