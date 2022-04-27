/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_philo_state.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 09:17:06 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/25 09:30:31 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_state(t_philo *philo)
{
	pthread_mutex_lock(philo->global->mutex_print);
	if (!(philo->global->dead))
	{
		printf(GRAY "\n%05llu ", (get_time() - philo->global->start_time));
		printf(YELLOW "%i ", philo->position);
		if (philo->state == EATING)
			printf(LIGHTGREEN "is eating");
		else if (philo->state == SLEEPING)
			printf(LIGHTBLUE "is sleeping");
		else if (philo->state == THINKING)
			printf(LIGHTPURPLE "is thinking");
		else if (philo->state == L_FORK)
			printf(WHITE "has taken left fork");
		else if (philo->state == R_FORK)
			printf(WHITE "has taken right fork");
		else if (philo->state == DEAD)
			printf(LIGHTRED "died");
	}
	printf(RESET);
	pthread_mutex_unlock(philo->global->mutex_print);
}
