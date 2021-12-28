# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 09:39:45 by ioriola           #+#    #+#              #
#    Updated: 2021/09/17 10:10:45 by ioriola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
SRCDIR		= src
SRCS		=	$(SRCDIR)/main.c\
				$(SRCDIR)/color_buffer.c\
				$(SRCDIR)/file_open.c\
				$(SRCDIR)/game.c\
				$(SRCDIR)/init_values.c\
				$(SRCDIR)/line_types.c\
				$(SRCDIR)/lines_process.c\
				$(SRCDIR)/map_check.c\
				$(SRCDIR)/map_player_get.c\
				$(SRCDIR)/minimap.c\
				$(SRCDIR)/move.c\
				$(SRCDIR)/mlx_tools.c\
				$(SRCDIR)/raycast.c\
				$(SRCDIR)/raycast_rays.c\
				$(SRCDIR)/raycast_tools.c\
				$(SRCDIR)/render_3d.c\
				$(SRCDIR)/settings_get.c

OBJS		= $(SRCS:.c=.o)

GCC			= gcc
FLAGS		= -g -Wall -Wextra -Werror

LIBDIR		= lib
LIBFTDIR	= $(LIBDIR)/libft
GNLDIR		= $(LIBDIR)/gnl
MLXDIR		= $(LIBDIR)/minilibx

LIBS		= -L$(LIBFTDIR) -lft -L$(GNLDIR) -lgnl -L$(MLXDIR) -lmlx
MLXFLAGS	= -framework OpenGL -framework AppKit

INCLUDE		= -I. -I$(LIBDIR) -I$(LIBFTDIR) -I$(GNLDIR) -I$(MLXDIR) -I$(SRCDIR)

$(NAME):	$(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(GNLDIR)
	$(MAKE) -C $(MLXDIR)
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
