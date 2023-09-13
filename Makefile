# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cormiere <cormiere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/06 18:07:35 by jdelsol-          #+#    #+#              #
#    Updated: 2023/09/13 19:21:40 by cormiere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3D
BONUS = cub3D_bonus
CFLAGS	= -Wextra -Werror -Wall -g3
LIBMLX	= ./MLX42

HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS	= srcs/All_free/ft_free_arrays.c \
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
		srcs/raycaster/mouse_mouvement.c

SRCS_BONUS =	srcs_bonus/All_free_bonus/ft_free_arrays_bonus.c \
		srcs_bonus/All_free_bonus/ft_free_structs_bonus.c \
		srcs_bonus/main_bonus.c \
		srcs_bonus/parsing_bonus/ft_attributes_securities_bonus.c \
		srcs_bonus/parsing_bonus/ft_check_args_bonus.c \
		srcs_bonus/parsing_bonus/ft_check_inside_row_col_bonus.c \
		srcs_bonus/parsing_bonus/ft_check_player_bonus.c \
		srcs_bonus/parsing_bonus/ft_check_row_and_col_bonus.c \
		srcs_bonus/parsing_bonus/ft_init_struct_bonus.c \
		srcs_bonus/parsing_bonus/ft_map_analysis_bonus.c \
		srcs_bonus/parsing_bonus/ft_parsing_bonus.c \
		srcs_bonus/parsing_bonus/ft_parsing_file_content_bonus.c \
		srcs_bonus/parsing_bonus/ft_parsing_shortcut_2_bonus.c \
		srcs_bonus/parsing_bonus/ft_parsing_shortcut_3_bonus.c \
		srcs_bonus/parsing_bonus/ft_parsing_shortcut_bonus.c \
		srcs_bonus/parsing_bonus/ft_set_struct_bonus.c \
		srcs_bonus/parsing_bonus/ft_verif_textures_bonus.c \
		srcs_bonus/raycaster_bonus/ft_3d_interpretation_bonus.c \
		srcs_bonus/raycaster_bonus/ft_all_hooks_bonus.c \
		srcs_bonus/raycaster_bonus/ft_all_mouvement_bonus.c \
		srcs_bonus/raycaster_bonus/ft_color_gestion_bonus.c \
		srcs_bonus/raycaster_bonus/ft_drawing_bonus.c \
		srcs_bonus/raycaster_bonus/ft_fov_bonus.c \
		srcs_bonus/raycaster_bonus/ft_get_map_infos_bonus.c \
		srcs_bonus/raycaster_bonus/ft_init_raycasting_bonus.c \
		srcs_bonus/raycaster_bonus/ft_launch_raycasting_bonus.c \
		srcs_bonus/raycaster_bonus/ft_raycasting_shorcuts_bonus.c \
		srcs_bonus/raycaster_bonus/ft_textures_gestion_bonus.c \
		srcs_bonus/raycaster_bonus/mouse_mouvement_bonus.c

OBJS	= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

LIBFT_PATH = libft/ --no-print-directory
LIBFT_NAME = libft/libft.a

all: libmlx $(LIBFT_NAME) $(NAME)

bonus:	libmlx $(LIBFT_NAME) $(BONUS)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@clang $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(LIBFT_NAME):
	make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	@clang $(OBJS) $(LIBFT_NAME) $(LIBS) $(HEADERS) -o $(NAME)

$(BONUS): $(OBJS_BONUS)
	@clang $(OBJS_BONUS) $(LIBFT_NAME) $(LIBS) $(HEADERS) -o $(BONUS)

clean:
	make clean -C ./libft
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	make fclean -C $(LIBFT_PATH)
	@rm -rf $(NAME) $(BONUS)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, bonus
