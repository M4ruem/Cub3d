/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_header.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:11:34 by cormiere          #+#    #+#             */
/*   Updated: 2023/08/13 12:48:14 by jdelsol-         ###   ########.fr       */
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
t_akinator *ft_set_up_akinator(char **attributes, char **map, int i);
int			ft_check_access(char *str);
int			ft_strcmp(char *s1, char *s2);
int			ft_which_case(char *pair);
t_akinator *ft_init_struct(int map_len);
int			ft_is_color_ok(char *tmp, int i, int nb_comas, char **tmp_tab);
int			ft_check_player(char **map, int i, int j, int player);
int			ft_convert_color(char *tmp, t_akinator *data, char c, char **tmp_tab);
int			ft_is_empty_file(char **content);
void		ft_free_data(t_akinator *data);
int			ft_check_if_textures_works(t_akinator *data);
int			ft_map_analysis(char **map);
char		**ft_arraydup(char **map, int index, int i);
char		**ft_rarraydup(char **map, int index, int i);
int			ft_max_line(char **map);
int			ft_check_multiple_map(char **map, const int len, int i, int j);
int			ft_is_line_empty(char *line);
int			ft_is_attrib_missing(t_akinator *data);
int			ft_is_from_map(char **map, int i, int j);
int			ft_check_vertical_multiple_map(char **map, const int len, int end_line, int j);

#endif
