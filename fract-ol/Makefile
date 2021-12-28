# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 09:39:45 by ioriola           #+#    #+#              #
#    Updated: 2021/09/24 10:18:06 by ioriola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
SRCDIR		= src
SRCS		=	$(SRCDIR)/main.c\
				$(SRCDIR)/color_manage.c\
				$(SRCDIR)/core.c\
				$(SRCDIR)/init_values.c\
				$(SRCDIR)/mlx_image.c\
				$(SRCDIR)/mlx_tools.c\
				$(SRCDIR)/sets.c

OBJS		= $(SRCS:.c=.o)

GCC			= gcc
FLAGS		= -g -Wall -Wextra -Werror

LIBDIR		= lib
LIBFTDIR	= $(LIBDIR)/libft
MLXDIR		= $(LIBDIR)/minilibx

LIBS		= -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx
MLXFLAGS	= -framework OpenGL -framework AppKit

INCLUDE		= -I. -I$(LIBDIR) -I$(LIBFTDIR) -I$(MLXDIR) -I$(SRCDIR)

$(NAME):	$(OBJS)
	$(GCC) -o $(NAME) $(OBJS) $(LIBS) $(MLXFLAGS)

.PHONY:	all clean fclean re

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(GCC) -o $@ -c $^ $(INCLUDE) $(FLAGS)
