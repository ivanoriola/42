# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 09:52:43 by ioriola           #+#    #+#              #
#    Updated: 2021/05/19 10:36:07 by ioriola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= libgnl.a
SRCS 	= get_next_line.c
OBJS	= $(SRCS:.c=.o)
RM		= @rm -f
LIBC	= ar -rcs
GCC		= @gcc
FLAGS	= -Wall -Wextra -Werror
INCLUDE	= -I. -I ../libft

$(NAME): ${OBJS}
	${LIBC} $(NAME) $(OBJS)
	ranlib $(NAME)

.PHONY:	all clean fclean re

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

%.o: %.c
	$(GCC) -o $@ -c $^ $(INCLUDE) $(FLAGS)
