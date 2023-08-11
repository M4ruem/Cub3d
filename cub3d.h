#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include "libft/libft.h"
#include "parsing/parsing_header.h"
#include "All_free/frees.h"

# define BUFFER_SIZE 42

typedef struct s_akinator
{
	char	*texture_paths[5];
	int		Floor_rgb[3];
	int		Ceiling_rgb[3];
	char	**map;
}	t_akinator;


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

void	ft_printf_map_error(int	error_key);

#endif
