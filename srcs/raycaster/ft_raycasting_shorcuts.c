/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_shorcuts.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:41:26 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/29 14:45:27 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycaster_header.h"

int	ft_still_inside(t_gpt *center, int x, int y)
{
	if ((x + 100 - center->player.x) > 0 && \
		(y + 100 - center->player.y) > 0 && \
		(x + 100 - center->player.x) < 200 && \
		(y + 100 - center->player.y) < 200)
		return (1);
	return (0);
}