/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:11:20 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/12 15:23:56 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_image_integrity(t_akinator *data)
{
	int	i;
	mlx_texture_t *tmp;

	tmp = NULL;
	i = 0;
	while (data->texture_paths[i])
	{
		tmp = mlx_load_png(texture_paths[i]);
		if (!tmp)
			return (0);
		free(tmp);
		i++;
	}
	return (1);
}

static int	ft_has_good_extension(t_akinator *data)
{
	int		i;
	char	**tmp_tab;
	char	*tmp;

	i = 0;
	while (data->texture_paths[i])
	{
		tmp_tab = ft_split(data->texture_paths[i], '/');
		if (!tmp_tab)
			return (0);
		tmp = ft_strdup(tmp_tab[ft_array_len(tmp_tab) - 1]);
		ft_free_multiple_array(tmp_tab, NULL, NULL);
		if (((ft_strcmp(tmp, ".cub") && ft_strlen(tmp) > 4))\
			|| (!ft_strcmp(tmp, ".cub") && ft_strlen(tmp) <= 4))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_if_textures_works(t_akinator *data)
{
	int	i;
	int	perms;

	i = -1;
	while (data->texture_paths[++i] && i < 4)
	{
		perms = ft_check_access(data->texture_paths[i]);
		if (perms != FILE_RDONLY && perms != FILE_RDWR && perms != FILE_RDWRX)	
		{
			ft_free_data(data);
			return (0);
		}
	}
	if (ft_image_integrity(data) || ft_has_good_extension(data))
	{
		ft_free_data(data);
		return (0);
	}
	return (1);
}