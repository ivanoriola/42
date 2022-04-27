/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:06:48 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/25 08:11:31 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define RESET			"\033[0m"
# define YELLOW			"\033[0;33m"
# define WHITE			"\033[0;37m"
# define GRAY			"\033[1;30m"
# define LIGHTRED		"\033[1;31m"
# define LIGHTGREEN		"\033[1;32m"
# define LIGHTBLUE		"\033[1;34m"
# define LIGHTPURPLE	"\033[1;35m"

# define DEAD		0
# define EATING 	1
# define SLEEPING 	2
# define THINKING 	3
# define L_FORK 	4
# define R_FORK 	5

typedef unsigned long long	t_time;

typedef struct s_global
{
	pthread_mutex_t	*mutex_list;
	pthread_mutex_t	*mutex_print;
	int				num_of_philos;
	t_time			time_to_die;
	t_time			time_to_eat;
	t_time			time_to_sleep;
	int				num_of_must_eat;
	t_time			start_time;
	int				dead;
}					t_global;

typedef struct s_philo
{
	t_global		*global;
	int				position;
	int				state;
	int				num_of_eat;
	t_time			start_time;
	pthread_t		thread_id;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}					t_philo;

int			args_ok(t_global *global, int argc, char **argv);
int			check_all_digits(int argc, char **argv);
void		check_num_of_eat(t_global *global, t_philo **philo_list);
void		check_time_to_die(t_philo	*philo);
void		create_pthreads(t_global *global, t_philo **philo_list);
int			exit_error(char const *str, int err_value);
void		free_memory(t_global *global, t_philo **philo_list);
t_time		get_time(void);
int			init_mutex_list(t_global *global, t_philo **philo_list);
t_philo		**init_philo_list(t_global	*global);
void		join_pthreads(t_global *global, t_philo **philo_list);
void		philo_eat(t_philo *philo);
int			philo_eaten(t_global *global, t_philo **philo_list);
void		philo_rest(t_philo *philo);
void		*philo_thread(void *var);
void		pick_forks(int method, t_philo *philo);
void		print_philo_state(t_philo *philo);
void		sleep_ms(int time);
void		use_forks(pthread_mutex_t *mutex, t_philo *philo, int fork);

/* ft_tools.c */
int			ft_atoi(char *str);
int			ft_isdigit(int c);
int			ft_isspace(char c);
size_t		ft_strlen(char const *str);

#endif