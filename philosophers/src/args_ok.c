/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_ok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:34:50 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/20 09:58:18 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_ok(t_global *global, int argc, char **argv)
{
	if (argc < 5 || argc > 6 || !check_all_digits(argc, argv))
		return (0);
	global->num_of_philos = ft_atoi(argv[1]);
	global->time_to_die = ft_atoi(argv[2]);
	global->time_to_eat = ft_atoi(argv[3]);
	global->time_to_sleep = ft_atoi(argv[4]);
	if (global->num_of_philos <= 0 || global->num_of_philos > 200
		|| global->time_to_die < 60 || global->time_to_eat < 60
		|| global->time_to_sleep < 60)
		return (0);
	if (argc == 6)
	{
		global->num_of_must_eat = ft_atoi(argv[5]);
		if (global->num_of_must_eat <= 0)
			return (0);
	}
	else
		global->num_of_must_eat = -1;
	global->dead = 0;
	return (1);
}
