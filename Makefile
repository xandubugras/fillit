# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubugra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 19:12:17 by adubugra          #+#    #+#              #
#    Updated: 2018/02/27 19:12:59 by adubugra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	gcc

FLAG =	-I. -Wall -Wextra -Werror

NAME =	fillit.a

LIB =	ar rc

RLIB =	ranlib

SRCS = main.c \
	   check_entry.c \
	   allocate_blocks.c \
	   solver.c \
	   construct_tetris_block.c \
	   set_list.c \
	   construct_map.c

OBJS = $(SRCS:.c=.o)

all: 	$(NAME)

$(NAME):
		@$(CC) $(FLAG) -c $(SRCS)
		@$(LIB) $(NAME) $(OBJS)
		@$(RLIB) $(NAME)
		@$(CC) $(FLAG) -o fillit $(SRCS) libft.a

clean:
		@/bin/rm -f $(OBJS)

fclean:	clean
		@/bin/rm -f $(NAME) fillit

re: fclean all

.PHONY: all clean fclean re
