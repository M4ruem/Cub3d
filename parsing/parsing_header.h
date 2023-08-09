/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:11:34 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/09 21:35:11 by cormiere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_HEADER_H
# define PARSING_HEADER_H

#include "../cub3d.h"

typedef struct s_akinator t_akinator;

int			ft_check_args(char **av);
char		**ft_check_file_content(char *file, int fd, char *line, char **content);
t_akinator	*ft_launch_parsing(char **av, int error);
int			ft_check_inside_line(char *line, int start, int end);
int			ft_check_inside_col(char **map, int col, int start, int end);
int			ft_check_horizontal_map_border(char **map, int i, int j);
int			ft_check_vertical_map_border(char **map, int i, int j);
int			ft_array_len(char **array);
t_akinator *ft_set_up_akinator(char **attributes, char **map, int i, int error);
int			ft_check_access(char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_which_case(char *pair);
t_akinator *ft_init_struct(int map_len);
int			ft_is_color_ok(char *tmp, int i, int nb_comas, char **tmp_tab);
int			ft_check_player(char **map, int i, int j);
int			ft_convert_color(char *tmp, t_akinator *data, char c);
int			ft_is_empty_file(char **content);
void		ft_free_data(t_akinator *data);
int			ft_check_texture_paths(t_akinator *data);
int			ft_map_analysis(char **map);
char		**ft_arraydup(char **map, int index, int i);

#endif
