/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:44:12 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/25 08:33:52 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	if (philo->state != DEAD)
	{
		if ((philo->num_of_eat < philo->global->num_of_must_eat)
			|| philo->global->num_of_must_eat < 0)
		{
			if ((philo->position % 2) && (philo->global->num_of_philos != 3))
				pick_forks(1, philo);
			else
				pick_forks(2, philo);
			if (philo->state != DEAD)
			{
				philo->start_time = get_time();
				philo->state = EATING;
				print_philo_state(philo);
				sleep_ms(philo->global->time_to_eat);
				check_time_to_die(philo);
			}
			if (philo->state != DEAD)
				philo->num_of_eat++;
			pthread_mutex_unlock(philo->left);
			pthread_mutex_unlock(philo->right);
		}
	}
}
