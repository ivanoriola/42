/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_time_to_die.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 08:35:23 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/21 09:59:48 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_time_to_die(t_philo	*philo)
{
	if (philo->state != DEAD && !(philo->global->dead))
	{
		if (((get_time() - philo->start_time)) > philo->global->time_to_die)
		{
			philo->state = DEAD;
			print_philo_state (philo);
			philo->global->dead = 1;
		}
	}
}
