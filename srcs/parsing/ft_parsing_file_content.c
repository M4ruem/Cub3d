/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_file_content.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:11:25 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/11 18:28:03 by jdelsol-         ###   ########.fr       */
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
		new_cont[i] = ft_strdup(old_cont[i]);
		if (!new_cont[i])
		{
			ft_free_multiple_array(new_cont, old_cont, NULL);
			return (NULL);
		}
	}
	new_cont[i] = ft_strdup(line);
	if (!new_cont[i])
	{
		ft_free_multiple_array(new_cont, old_cont, NULL);
		return (NULL);
	}
	ft_free_multiple_array(old_cont, NULL, NULL);
	return (new_cont);
}

char **ft_check_file_content(char *file, int fd, char *line, char **content)
{
	content = ft_calloc(sizeof(char *), 1);
	if (!content)
		return (NULL);
	fd = open(file, O_RDONLY, 0644);
	while (42)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (line[ft_strlen(line) - 1] == '\n' && (ft_strlen(line) > 1))
			line[ft_strlen(line) - 1] = 0;
		content = ft_add_line(content, line, -1, ft_array_len(content));
		if (!content)
			return (NULL);
		free(line);
	}
	if (ft_is_empty_file(content))
		ft_printf_fd(2, "Error\nEMPTY FILE\n");
	if (ft_is_empty_file(content))
	{
		free(content);
		return (NULL);
	}
	return (content);
}
