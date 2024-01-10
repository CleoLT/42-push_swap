# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ale-tron <ale-tron@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 16:48:17 by ale-tron          #+#    #+#              #
#    Updated: 2024/01/10 17:57:21 by ale-tron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = push_swap

CC = gcc

CFLAGS = -Wextra -Werror -Wall

RM = rm -f

SRC_DIR = src/

LIBFT_DIR = libft/

OBJ_DIR = obj/

SRC = push_swap.c handle_errors.c fill_stack.c utils.c commands/swap.c commands/rotate.c

INCLUDE = include/push_swap.h Makefile libft/*.c

OBJ = ${addprefix ${OBJ_DIR},${SRC:.c=.o}}


all: ${NAME}

${NAME}: ${OBJ}
		make -C $(LIBFT_DIR)
		${CC} ${CFLAGS} -o ${NAME} ${OBJ} -L ./libft -lft

${OBJ_DIR}%.o: ${SRC_DIR}%.c ${INCLUDE}
		@mkdir -p ${OBJ_DIR}/commands
		${CC} ${CFLAGS} -c -o $@ $<
		
clean:
		$(RM) ${OBJ}
		cd $(LIBFT_DIR) && make clean

fclean: clean
		$(RM) ${NAME}
		cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
