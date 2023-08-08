/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:11:34 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/08 21:12:06 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HEADER_H
# define PARSING_HEADER_H

void	ft_free_multiple_array(char **ar1, char **ar2, char **ar3);
int		ft_check_args(char **av);
char	**ft_check_file_content(char *file);
char	**ft_launch_parsing(char **av);
int		ft_check_inside_line(char *line, int start, int end);
int		ft_check_inside_col(char **map, int col, int start, int end);
int		ft_check_horizontal_map_border(char **map, int i, int j);
int		ft_check_vertical_map_border(char **map, int i, int j);
char	*ft_self_made_strcpy(char *str);
int		ft_array_len(char **array);

#endif
