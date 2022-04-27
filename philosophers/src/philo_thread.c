/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:38:54 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/21 09:36:30 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_thread(void *var)
{
	t_philo	*philo;

	philo = (t_philo *)var;
	if ((philo->position) % 2 == 0)
		usleep(500);
	philo->start_time = get_time();
	while (philo->state != DEAD && !(philo->global->dead))
	{
		philo_eat(philo);
		if (philo->num_of_eat == philo->global->num_of_must_eat)
			return (NULL);
		philo_rest(philo);
		check_time_to_die(philo);
		philo->state = THINKING;
		print_philo_state(philo);
	}
	return (NULL);
}
