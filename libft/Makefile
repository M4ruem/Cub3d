# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdelsol- <jdelsol-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 13:57:27 by lflandri          #+#    #+#              #
#    Updated: 2023/09/05 17:15:51 by jdelsol-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC 		= ft_bzero.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_isuppercase.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_strchr.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strncmp.c\
			ft_strndup.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_atoi.c\
			ft_calloc.c\
			ft_strdup.c\
			ft_substr.c\
			ft_strjoin.c\
			ft_strtrim.c\
			ft_split.c\
			ft_itoa.c\
			ft_strmapi.c\
			ft_striteri.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_printf_fd.c\
			all_prts_fd/ft_prt_char_str_fd.c\
			all_prts_fd/ft_prt_hex_fd.c\
			all_prts_fd/ft_prt_nbr_fd.c\
			ft_lstnew_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstadd_back_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstmap_bonus.c\
			ft_printf.c\
			ft_write_all.c\
			nbr_writer.c\
			get_next_line.c\
			get_next_line_utils.c\
			ft_error.c\
			ft_lstget_elt.c\
			ft_len_strtab.c\
			ft_join.c\



NAME 		= libft.a

MAKEFLAGS	= --no-print-directory

#couleur
BLACK		=\\e[0;30m
GREY		=\\e[1;30m
BLACKRED	=\\e[0;31m
PINK		=\\e[1;31m
BLACKGREEN	=\\e[0;32m
WHITEGREEN	=\\e[1;32m
ORANGE		=\\e[0;33m
YELLOW		=\\e[1;33m
BLACKBLUE	=\\e[0;34m
WHITEBLUE	=\\e[1;34m
BLACKPURPLE	=\\e[0;35m
WHITEPURPLE	=\\e[1;35m
BLACKCYAN	=\\e[0;36m
WHITECYAN	=\\e[1;36m
WHITEGREY	=\\e[0;37m
WHITE		=\\e[1;37m

NEUTRE		= \\e[0;m

#effect
BLINK		=\\e[5m

RESET		=\\e[25m

PO 			= ${SRC:.c=.o}

all :		${NAME}
			@echo "${WHITEGREEN}Bibliotheque \"${BLINK}${NAME}${RESET}\" PRET À L'EMPLOI !${NEUTRE}"

.c.o :
			@echo -n "${WHITE}"
			@clang -I -Wall -Wextra -Werror -Ofast -c $< -o ${<:.c=.o}
			@echo -n "${NEUTRE}"

${NAME}:
			@echo "${BLACKPURPLE}=============== CRÉATION LIBFT ===============${NEUTRE}"
			@make ${PO}
			@echo -n "${YELLOW}"
			@ar rc ${NAME} ${PO}
			@echo "${BLACKPURPLE}============= FIN CRÉATION LIBFT =============${NEUTRE}"

clean :
			@echo -n "${BLACKRED}"
			rm -f ${PO}
			@echo -n "${NEUTRE}"

fclean :	clean
			@echo -n "${BLACKRED}"
			rm -f ${NAME}
			@echo "${ORANGE}           !!! NON !!! ${BLACKRED}"

			@echo "          _ ._  _ , _ ._"
			@echo "        (_ ' (    )_  .__)"
			@echo "      ( (  (    )    )  ) _)"
			@echo "     (__ (_   (_ . _) _) ,__)"
			@echo "          ~~ \ ' . / ~~ "
			@echo "              ;   ;"
			@echo "              /   \\"
			@echo "_____________/_ __ \\_____________"
			@echo "${ORANGE}         !!! MON Cub3d !!!"




			@echo -n "${NEUTRE}"

re :		fclean all

.PHONY : all clean fclean re bonus
