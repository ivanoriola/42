/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:47:32 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/20 08:05:05 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	use_forks(pthread_mutex_t *mutex, t_philo *philo, int fork)
{
	pthread_mutex_lock(mutex);
	check_time_to_die(philo);
	if (philo->state != DEAD)
	{
		philo->state = fork;
		print_philo_state(philo);
	}
}
