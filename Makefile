# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmarceau <rmarceau@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 16:45:42 by rmarceau          #+#    #+#              #
#    Updated: 2023/05/29 01:49:46 by rmarceau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

INC_DIR = include
SRCS_DIR = src
OBJS_DIR = objs

SRCS = push_swap.c parsing.c indexing.c\
	lst_utils.c sort_utils.c utils.c \
	finish.c \
	push.c swap.c rotate.c reverse_rotate.c \
	sort_small.c sort_big.c \

OBJS = $(addprefix ${OBJS_DIR}/, ${SRCS:%.c=%.o})

LIBFT_PATH = libft
LIBFT_LIB = ${LIBFT_PATH}/libft.a
LIBFT_INC = ${LIBFT_PATH}/include

GREEN	= \033[32;1m
CYAN	= \033[36;1m
RED		= \033[0;31m
BOLD	= \033[1m
RESET	= \033[0m
MAGENTA	=\033[0;95m

all: ${LIBFT_LIB} ${NAME}

${LIBFT_LIB}:
	@make -C ${LIBFT_PATH}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	@${CC} ${CFLAGS} -I ${INC_DIR} -I ${LIBFT_INC} -c $< -o $@
	@echo "$(GREEN)Compiling: $<$(RESET)$(MAGENTA)              [OK]$(RESET)"

${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} -o ${NAME}
	@echo "$(GREEN)Compilation terminé avec succès !"

clean:
	@make clean -C ${LIBFT_PATH}
	@${RM} ${OBJS_DIR}
	@echo "$(RED)$(BOLD)Nettoyage effectué avec succès !"

fclean:	clean
	@make fclean -C ${LIBFT_PATH}
	@${RM} ${NAME}

re: fclean all
	@echo "$(CYAN)Recompilation Terminé !"

.PHONY: all clean fclean re
