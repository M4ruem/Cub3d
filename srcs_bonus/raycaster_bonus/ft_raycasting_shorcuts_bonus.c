/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_shorcuts_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:41:26 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/09/13 18:34:39 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header_bonus.h"

int	ft_still_inside(t_gpt *center, int x, int y)
{
	const int	tmp_x = x + 100 - center->player.x;
	const int	tmp_y = y + 100 - center->player.y;

	if ((tmp_x) > 0 && (tmp_y) > 0 && (tmp_x) < 200 && (tmp_y) < 200)
		return (1);
	return (0);
}
