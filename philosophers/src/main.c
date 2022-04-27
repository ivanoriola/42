/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:01:56 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/25 08:13:54 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_global	global;
	t_philo		**philo_list;

	if (!args_ok(&global, argc, argv))
		return (exit_error("Wrong arguments", 1));
	philo_list = init_philo_list(&global);
	if (!philo_list || !init_mutex_list(&global, philo_list))
	{
		free_memory(&global, philo_list);
		return (exit_error("Wrong memory allocation", 1));
	}
	global.start_time = get_time();
	create_pthreads(&global, philo_list);
	join_pthreads(&global, philo_list);
	check_num_of_eat(&global, philo_list);
	free_memory(&global, philo_list);
	pthread_exit(NULL);
	return (0);
}
