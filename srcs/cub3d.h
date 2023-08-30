/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 13:48:27 by jdelsol-          #+#    #+#             */
/*   Updated: 2023/08/30 16:04:05 by jdelsol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "parsing/parsing_header.h"
# include "raycaster/raycaster_header.h"
# include "All_free/frees.h"

# define BUFFER_SIZE 42
# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_akinator
{
	char	*texture_paths[5];
	int		floor_rgb[3];
	int		ceiling_rgb[3];
	char	**map;
}	t_akinator;

typedef struct s_player
{
	double	angle;
	double	x;
	double	y;

} t_player;

typedef struct s_3d
{
	double	ray;
	double	x;
	double	y;
	double	angle;
	char	dir;
}	t_3d;

typedef struct s_textures
{
	mlx_texture_t *north;
	mlx_texture_t *south;
	mlx_texture_t *east;
	mlx_texture_t *west;
}	t_textures;

typedef struct s_gpt
{
	t_akinator		*data;
	mlx_t			*mlx;
	t_player		player;
	mlx_image_t		*minimap;
	int				map_height;
	int				map_width;
	char			player_start_sens;
	int				player_start_xy[2];
	t_3d			fov[WIDTH];
	mlx_image_t		*fov_img;
	t_textures		textures_tab;
}	t_gpt;

enum	e_file_perm
{
	FILE_KO,
	FILE_OK,
	FILE_NO_PERMS,
	FILE_RDONLY,
	FILE_WRONLY,
	FILE_XONLY,
	FILE_RDWR,
	FILE_RDX,
	FILE_WRX,
	FILE_RDWRX,
	IS_A_DIREC,
};

enum	e_map_parsing_error
{
	HOLE_IN_LINE,
	INCOMPLETE_LINE,
	BAD_LINE,
	LINES_OK,
	HOLE_IN_COL,
	INCOMPLETE_COL,
	BAD_COL,
	COL_OK,
	PLAYER_IS_BRINGING_MILK,
	PLAYER_OKAY,
	PLAYER_KAYO,
	TOO_MANY_PEOPLE_AAAAAH,
	INTRUDER_CHARACTER,
};

void	ft_printf_map_error(int error_key);
void	ft_printf_files_errors(int error_key, char *file);

#endif
