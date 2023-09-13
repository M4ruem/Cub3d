/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_struct_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:31:54 by cormiere          #+#    #+#             */
/*   Updated: 2023/09/13 18:33:55 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	ft_check_color(char *color, t_akinator *data, char c)
{
	int		start;
	int		end;
	char	*tmp;
	int		error;

	start = 0;
	while (color[start] == ' ' || color[start] == '\t')
		start++;
	end = start;
	while (color[end] && (color[end] != ' ' || color[end] != '\t'))
		end++;
	if ((c == 'F' && (data->floor_rgb[0] != -1 || data->floor_rgb[1] != -1 \
		|| data->floor_rgb[2] != -1)) || (c == 'C'\
		&& (data->ceiling_rgb[0] != -1 || data->ceiling_rgb[1] != -1 \
		|| data->ceiling_rgb[2] != -1)))
		return (0);
	tmp = ft_strndup(&color[start], end - start);
	if (!tmp)
		return (0);
	if (!ft_is_color_ok(tmp, -1, 0, NULL))
		return (0);
	error = ft_convert_color(tmp, data, c, NULL);
	if (!error)
		return (0);
	return (1);
}

static int	ft_check_texture(char *texture, t_akinator *data, char *pair)
{
	int		start;
	int		end;
	int		index;

	start = 0;
	while (texture[start] == ' ' || texture[start] == '\t')
		start++;
	end = start;
	while (texture[end] && (texture[end] != ' ' || texture[end] != '\t'))
		end++;
	index = ft_which_case(pair);
	if (index < 0 || index > 3)
		return (0);
	if (data->texture_paths[index])
	{
		ft_free_sp_array(data->texture_paths);
		return (0);
	}
	data->texture_paths[index] = ft_strndup(&texture[start], end - start);
	if (!data->texture_paths[index])
	{
		ft_free_sp_array(data->texture_paths);
		return (0);
	}
	return (1);
}

static int	ft_check_case(char **attributes, t_akinator *data, int i, int j)
{
	char	pair[2];

	if (ft_isuppercase(attributes[i][j + 1]) && (attributes[i][j + 2] == ' ' \
		|| attributes[i][j + 2] == '\t'))
	{
		pair[0] = attributes[i][j];
		pair[1] = attributes[i][j + 1];
		if (!ft_strcmp(pair, "NO") || !ft_strcmp(pair, "SO") \
			|| !ft_strcmp(pair, "EA") || !ft_strcmp(pair, "WE"))
			return (ft_check_texture(&attributes[i][j + 2], data, pair));
	}
	else if ((attributes[i][j + 1] == ' ' || attributes[i][j + 1] == '\t'))
	{
		if (attributes[i][j] == 'F' || attributes[i][j] == 'C')
		{
			return (ft_check_color(&attributes[i][j + 1], data,
				attributes[i][j]));
		}
	}
	return (0);
}

static int	ft_attributes_analysis(char **attributes, t_akinator *data,
	int i, int j)
{
	while (attributes[++i])
	{
		j = -1;
		while (attributes[i][++j])
		{
			if (ft_isuppercase(attributes[i][j])
				&& (j == 0 || (j > 0 && (attributes[i][j - 1] == '\t' \
				&& attributes[i][j - 1] == ' '))))
			{
				if (!ft_check_case(attributes, data, i, j))
				{
					ft_printf_fd(2, "Error\nATTRIBUTE ERROR\n");
					return (0);
				}
				break ;
			}
		}
	}
	if (ft_is_attrib_missing(data))
		return (0);
	ft_free_multiple_array(attributes, NULL);
	return (1);
}

t_akinator	*ft_set_up_akinator(char **attributes, char **map, int i)
{
	t_akinator	*data;

	data = ft_init_struct(ft_array_len(map));
	if (!data)
		ft_free_multiple_array(map, attributes);
	if (!data)
		return (NULL);
	while (map[++i])
	{
		data->map[i] = ft_strdup(map[i]);
		if (!data->map[i])
		{
			ft_free_multiple_array(attributes, map);
			ft_free_data(data);
			return (NULL);
		}
	}
	ft_free_multiple_array(map, NULL);
	if (!ft_attributes_analysis(attributes, data, -1, -1))
	{
		ft_free_data(data);
		return (NULL);
	}
	return (data);
}
