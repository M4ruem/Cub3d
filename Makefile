# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 18:07:35 by jdelsol-          #+#    #+#              #
#    Updated: 2023/09/10 18:26:03 by jdelsol-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= cub3D
CFLAGS	:= -Wextra -Werror -Wall -g3
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS	:= srcs/All_free/ft_free_arrays.c \
		srcs/All_free/ft_free_structs.c \
		srcs/main.c \
		srcs/parsing/ft_attributes_securities.c \
		srcs/parsing/ft_check_args.c \
		srcs/parsing/ft_check_inside_row_col.c \
		srcs/parsing/ft_check_player.c \
		srcs/parsing/ft_check_row_and_col.c \
		srcs/parsing/ft_init_struct.c \
		srcs/parsing/ft_map_analysis.c \
		srcs/parsing/ft_parsing.c \
		srcs/parsing/ft_parsing_file_content.c \
		srcs/parsing/ft_parsing_shortcut_2.c \
		srcs/parsing/ft_parsing_shortcut_3.c \
		srcs/parsing/ft_parsing_shortcut.c \
		srcs/parsing/ft_set_struct.c \
		srcs/parsing/ft_verif_textures.c \
		srcs/raycaster/ft_3d_interpretation.c \
		srcs/raycaster/ft_all_hooks.c \
		srcs/raycaster/ft_all_mouvement.c \
		srcs/raycaster/ft_color_gestion.c \
		srcs/raycaster/ft_drawing.c \
		srcs/raycaster/ft_fov.c \
		srcs/raycaster/ft_get_map_infos.c \
		srcs/raycaster/ft_init_raycasting.c \
		srcs/raycaster/ft_launch_raycasting.c \
		srcs/raycaster/ft_raycasting_shorcuts.c \
		srcs/raycaster/ft_textures_gestion.c \
		srcs/raycaster/mouse_mouvement.c \


OBJS	:= ${SRCS:.c=.o}

LIBFT_PATH = libft/ --no-print-directory
LIBFT_NAME = libft/libft.a

all: libmlx $(LIBFT_NAME) $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@clang $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	@clang $(OBJS) $(LIBFT_NAME) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	make clean -C ./libft
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	make fclean -C $(LIBFT_PATH)
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
