NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a
SRCS		=	ft_printf.c \
				getters.c \
				printchar.c \
				printhex.c \
				printint.c \
				printpointer.c \
				printstr.c \
				printuint.c \
				tools1.c \
				tools2.c \
				tools3.c
OBJS		= $(SRCS:.c=.o)
RM			= rm -f
LIBC		= ar -rcs
FLAGS		= -Wall -Wextra -Werror -O3 -g3
INCS		= .
COMPILER	= gcc

.c.o:
	${COMPILER} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME): ${OBJS}
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	${LIBC} $(NAME) $(OBJS)

all: $(NAME)

fclean: clean
	$(RM) $(NAME) $(bonus)
	make fclean -C $(LIBFT)

clean:
	$(RM) -f $(OBJS) $(OBJS_B)
	make clean -C $(LIBFT)

re: fclean all

bonus: all
