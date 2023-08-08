/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_file_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:11:25 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/08 21:11:56 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_array_len(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

char	*ft_self_made_strcpy(char *str)
{
	char	*new_str;
	int 	i;

	i = 0;
	if (!str)
		return (NULL);
	new_str = ft_calloc(sizeof(char), (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}

static char	**ft_add_line(char **old_cont, char *line, 	int i, int nb_line)
{
	char	**new_cont;

	new_cont = ft_calloc(sizeof(char *), nb_line + 2);
	if (!new_cont)
	{
		ft_free_multiple_array(old_cont, NULL, NULL);
		return (NULL);
	}
	while (old_cont[++i])
	{
		new_cont[i] = ft_self_made_strcpy(old_cont[i]);
		if (!new_cont[i])
		{
			ft_free_multiple_array(new_cont, old_cont, NULL);
			return (NULL);
		}
	}
	new_cont[i] = ft_self_made_strcpy(line);
	if (!new_cont[i])
	{
		ft_free_multiple_array(new_cont, old_cont, NULL);
		return (NULL);
	}
	ft_free_multiple_array(old_cont, NULL, NULL);
	return (new_cont);
}

char **ft_check_file_content(char *file)
{
	char	*line;
	char	**content;
	int		fd;
	int		nb_row;

	nb_row = 0;
	content = ft_calloc(sizeof(char *), 1);
	if (!content)
		return (NULL);
	fd = open(file, O_RDONLY, 0644);
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		content = ft_add_line(content, line, -1, ft_array_len(content));
		if (!content)
			return (NULL);
		free(line);
	}
	return (content);
}
