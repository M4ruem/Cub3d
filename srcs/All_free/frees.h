/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 14:58:06 by cormiere          #+#    #+#             */
/*   Updated: 2023/09/09 18:30:39 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREES_H
# define FREES_H

# include "../cub3d.h"

typedef struct s_gpt	t_gpt;

void	ft_free_sp_array(char **array);
void	ft_free_multiple_array(char **ar1, char **ar2);
void	ft_free_center(t_gpt *center);
void	ft_free_texture_paths(char **array);

#endif
