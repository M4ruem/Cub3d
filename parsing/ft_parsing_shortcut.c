/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_shortcut.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:04:52 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/10 21:22:09 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_which_case(char *pair)
{
	if (!ft_strcmp(pair, "NO"))
		return (0);
	else if (!ft_strcmp(pair, "SO"))
		return (1);
	else if (!ft_strcmp(pair, "EA"))
		return (2);
	else if (!ft_strcmp(pair, "WE"))
		return (3);
	else
		return (-1);
}

int	ft_is_color_ok(char *tmp, int i, int nb_commas, char	**tmp_tab)
{
	while (tmp[++i])
	{
		if ((tmp[i] == ',' && (i == 0 || !ft_isdigit(tmp[i - 1]) \
			|| !ft_isdigit(tmp[i + 1]) || nb_commas == 2)) \
			|| ft_isalpha(tmp[i]))
		{
			free(tmp);
			return (0);
		}
		else if (tmp[i] == ',')
			nb_commas++;
	}
	tmp_tab = ft_split(tmp, ',');
	i = -1;
	while (tmp_tab[++i])
	{
		if (ft_atoi(tmp_tab[i]) > 255 || ft_atoi(tmp_tab[i]) < 0)
		{
			free(tmp);
			ft_free_multiple_array(tmp_tab, NULL, NULL);
			return (0);
		}
	}
	ft_free_multiple_array(tmp_tab, NULL, NULL);
	return (1);
}

int	ft_convert_color(char *tmp, t_akinator *data, char c, char **tmp_tab)
{
	int		i;

	i = -1;
	tmp_tab = ft_split(tmp, ',');
	free(tmp);
	if (!tmp_tab)
		return (0);
	if (ft_array_len(tmp_tab) < 3)
	{
		ft_free_multiple_array(tmp_tab, NULL, NULL);
		return (0);
	}
	if (c == 'F')
	{
		while (++i < 3)
			data->Floor_rgb[i] = ft_atoi(tmp_tab[i]);
	}
	if (c == 'C')
	{
		i = -1;
		while (++i < 3)
			data->Ceiling_rgb[i] = ft_atoi(tmp_tab[i]);
	}
	ft_free_multiple_array(tmp_tab, NULL, NULL);
	return (1);
}

int	ft_is_empty_file(char **content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		if (content[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_texture_paths(t_akinator *data)
{
	int	i;
	int	perms;

	i = 0;
	while (data->texture_paths[i] && i < 4)
	{
		perms = ft_check_access(data->texture_paths[i]);
		if (perms != FILE_RDONLY && perms != FILE_RDWR
			&& perms != FILE_RDWRX)
		{
			ft_free_data(data);
			return (0);
		}
		i++;
	}
	return (1);
}
