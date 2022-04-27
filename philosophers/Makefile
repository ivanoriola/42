# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 08:54:23 by ioriola           #+#    #+#              #
#    Updated: 2022/04/25 08:12:01 by ioriola          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_BOLD		=\e[1m
_R			=\e[0m

_RED		=\e[91m
_GREEN		=\e[92m
_YELLOW		=\e[93m
_BLUE		=\e[94m
_MAGENTA	=\e[35m
_CYAN		=\e[96m
_WHITE		=\e[97m

NAME = philo

SRC =	args_ok.c \
		check_all_digits.c \
		check_num_of_eat.c \
		check_time_to_die.c \
		create_pthreads.c \
		exit_error.c \
		free_memory.c \
		ft_tools.c \
		get_time.c \
		init_mutex_list.c \
		init_philo_list.c \
		join_pthreads.c \
		main.c \
		philo_eat.c \
		philo_eaten.c \
		philo_rest.c \
		philo_thread.c \
		pick_forks.c \
		print_philo_state.c \
		sleep_ms.c \
		use_forks.c

### Librairies ###
HEADERS = includes
INC = philo.h
vpath %.h $(HEADERS)

### Sources ###
SRCS_DIR = src
SRCS = $(addprefix $(SRCS_DIR)/,$(SRC))

### Objets ###
OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
vpath %.c $(SRCS_DIR)

### Flags ###
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -I $(HEADERS) -c $< -o $@ 
	@printf "$(_BLUE)Compiling:$(_WHITE) $<$(_R)\n"

$(NAME): title $(OBJ)
	@printf "\n$(_WHITE)Compilation $(_GREEN)completed.$(_R)\n"
	@(gcc $(FLAGS) -I $(HEADERS) $(OBJ) -o $(NAME) -lpthread)
	@(printf "\n$(_WHITE)Executable $(_YELLOW)$(NAME)$(_WHITE) created.$(_R)\n")

clean:
	@printf "\n$(_BLUE)Clean$(_R)\n"
	@(rm -rf ./srcs/*.o)
	@(rm -rf $(OBJ_DIR))

fclean:	clean
	@printf "\n$(_BLUE)Fclean$(_R)\n"
	@(rm -rf $(NAME))

re:	fclean all

title:
	@printf "\n\e[1;93m Philosophers $(_R)\n"
	@printf "\e[1;93m¯¯¯¯¯¯¯¯¯¯¯¯¯¯$(_R)\n"

.PHONY:	all clean fclean re title
