/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 14:11:20 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/14 14:11:39 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	ft_image_integrity(t_akinator *data)
{
	int				i;
	mlx_texture_t	*tmp;

	tmp = NULL;
	i = 0;
	while (data->texture_paths[i])
	{
		tmp = mlx_load_png(data->texture_paths[i]);
		if (!tmp)
		{
			ft_printf_fd(2, "Error\nINVALID TEXTURE\n");
			return (0);
		}
		free(tmp);
		i++;
	}
	return (1);
}

static int	ft_has_good_extension(t_akinator *data, int i)
{
	int		j;
	char	**tmp_tab;
	char	*tmp;

	while (data->texture_paths[++i])
	{
		j = 0;
		tmp_tab = ft_split(data->texture_paths[i], '/');
		if (!tmp_tab)
			return (0);
		tmp = ft_strdup(tmp_tab[ft_array_len(tmp_tab) - 1]);
		ft_free_multiple_array(tmp_tab, NULL, NULL);
		while (tmp[j] && tmp[j] != '.')
			j++;
		if ((ft_strcmp(&tmp[j], ".png") && ft_strlen(tmp) > 4)
			|| (!ft_strcmp(&tmp[j], ".png") && ft_strlen(tmp) <= 4))
		{
			free(tmp);
			ft_printf_fd(2, "Error\nINVALID EXTENSIONS\n");
			return (0);
		}
		free(tmp);
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
			ft_printf_files_errors(perms, data->texture_paths[i]);
			ft_free_data(data);
			return (0);
		}
	}
	if (!ft_has_good_extension(data, -1))
	{
		ft_free_data(data);
		return (0);
	}
	else if (!ft_image_integrity(data))
	{
		ft_free_data(data);
		return (0);
	}
	return (1);
}
