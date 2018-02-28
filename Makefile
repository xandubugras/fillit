# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubugra <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 19:12:17 by adubugra          #+#    #+#              #
#    Updated: 2018/02/27 16:53:30 by adubugra         ###   ########.fr        #
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
		@/bin/rm -f $(OBJS)
		@$(CC) $(FLAG) -o a.out $(SRCS) libft.a

clean:
		@/bin/rm -f $(OBJS)

fclean:	clean
		@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
