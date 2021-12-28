# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 09:39:45 by ioriola           #+#    #+#              #
#    Updated: 2021/10/19 07:20:15 by ioriola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#COMPILATION
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
LIBFTDIR	= libft
LIBS		= -L$(LIBFTDIR) -lft 
INCLUDE		= -I. -I$(LIBFTDIR) -I$(SRCDIR)
#VALUES
CNAME		= client
SNAME		= server
#MISC
NOCOLOR	= \033[0m
GREEN	= \033[0;32m
RED		= \033[0;31m
ORANGE	= \033[0;33m
#SOURCES
SRCDIR		= src
CSRCS		= 	$(SRCDIR)/client.c
SSRCS		= 	$(SRCDIR)/server.c
COBJS		= 	${CSRCS:.c=.o}
SOBJS		= 	${SSRCS:.c=.o}

all:		$(CNAME) $(SNAME)

%.o: %.c
			$(CC) -o $@ -c $< $(INCLUDE) $(CFLAGS)
$(SNAME):	${SOBJS}
			$(MAKE) -C $(LIBFTDIR)
			@$(CC) $(SOBJS) -o $(SNAME) $(LIBS)
			@echo "${GREEN}Server made"
			@echo "${NOCOLOR}"
$(CNAME):	${COBJS}
			$(MAKE) -C $(LIBFTDIR)
			@$(CC) $(COBJS) -o $(CNAME) $(LIBS)
			@echo "${GREEN}Client made"
			@echo "${NOCOLOR}"
clean:
			@rm -f *.o; rm -f *~
			@echo "${ORANGE}Temporary files removed"
fclean: clean
			@rm -f $(CNAME) $(SNAME)
			@echo "${RED}Execs deleted"
			@echo "${NOCOLOR}"
re:		fclean all
.PHONY: all clean fclean re