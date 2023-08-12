NAME		=	Cub3d

LIBMLX	:= ./raycaster/lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

OBJS	:= ${SRCS:.c=.o}

SRCS		=	main.c\
				parsing/ft_attributes_securities.c\
				parsing/ft_parsing.c\
				parsing/ft_check_args.c\
				parsing/ft_parsing_file_content.c\
				parsing/ft_check_inside_row_col.c\
				parsing/ft_check_player.c\
				parsing/ft_check_row_and_col.c\
				parsing/ft_init_struct.c\
				parsing/ft_map_analysis.c\
				parsing/ft_parsing_shortcut.c\
				parsing/ft_parsing_shortcut_2.c\
				parsing/ft_parsing_shortcut_3.c\
				parsing/ft_set_struct.c\
				parsing/ft_verif_textures.c\
				All_free/ft_free_structs.c\
				All_free/ft_free_arrays.c\
				$(shell find ./src -iname "*.c")

OBJS		=	${SRCS:.c=.o}

CC			=	@clang

CFLAGS		=	-Wall -Werror -Wextra -Iinclude -ldl -lglfw -pthread -lm -Wunreachable-code -Ofast -g3


LIBFT_PATH = libft/ --no-print-directory
LIBFT_NAME = libft/libft.a

RM			=	@rm -rf

RED		=	\033[0;31m

DEFAULT		=	\033[0m

PURPLE	= \033[38;5;213m

PHILO	= @printf "$(PURPLE)\033[5m _________      ___.   ________      .___ \n"
PHILO1	= printf "$(PURPLE)\033[5m \_   ___ \ __ _\_ |__ \_____  \   __| _/\n"
PHILO2	= printf "$(PURPLE)\033[5m /    \  \/|  |  \ __ \  _(__  <  / __ | \n"
PHILO3	= printf "$(PURPLE)\033[5m \     \___|  |  / \_\ \/       \/ /_/ | \n"
PHILO4	= printf "$(PURPLE)\033[5m  \______  /____/|___  /______  /\____ | \n"
PHILO5	= printf "$(PURPLE)\033[5m         \/          \/       \/      \/ \n"

PHIL = $(PHILO);$(PHILO1);$(PHILO2);$(PHILO3);$(PHILO4);$(PHILO5); \

all: $(LIBFT_NAME) ${NAME}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		${CC} ${CFLAGS} ${OBJS} $(LIBFT_NAME) -o ${NAME}
		${PHIL}

$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

clean:
		make clean -C ./libft
		${RM} ${OBJS}

fclean:		clean
		make fclean -C $(LIBFT_PATH)
		${RM} ${NAME}
		@echo "${RED}Erased by the code destroyer${DEFAULT}"

re:			fclean
		@$(MAKE) all --no-print-directory

.PHONY:		all clean fclean re
