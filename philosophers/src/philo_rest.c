/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:45:22 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/20 08:04:02 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_rest(t_philo *philo)
{
	if (philo->state != DEAD)
	{
		philo->state = SLEEPING;
		print_philo_state(philo);
		sleep_ms(philo->global->time_to_sleep);
	}
}
