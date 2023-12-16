# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 16:48:17 by ale-tron          #+#    #+#              #
#    Updated: 2023/12/16 15:58:21 by ale-tron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap

CC = gcc

CFLAGS = -Wextra -Werror -Wall

RM = rm -f

SRC_DIR = src/

LIBFT_DIR = libft/

OBJ_DIR = obj/

SRC = push_swap.c ft_check_error.c

INCLUDE = include/push_swap.h libft/* Makefile

OBJ = ${addprefix ${OBJ_DIR},${SRC:.c=.o}}


all: ${NAME}

${OBJ_DIR}%.o: ${SRC_DIR}%.c ${INCLUDE}
		${CC} -c $< -o $@

${OBJ_DIR}:
		mkdir obj

${NAME}: ${OBJ_DIR} ${OBJ}
		make -C $(LIBFT_DIR)
		${CC} ${CFLAGS} ${OBJ} -o ${NAME} -L ./libft -lft 

clean:
		$(RM) -r ${OBJ_DIR}
		cd $(LIBFT_DIR) && make clean

fclean: clean
		$(RM) ${NAME}
		cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
