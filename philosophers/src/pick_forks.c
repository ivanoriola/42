/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:46:22 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/25 08:41:25 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pick_forks(int turn, t_philo *philo)
{
	if ((turn == 1) && (philo->global->num_of_philos != 1))
	{
		use_forks(philo->left, philo, L_FORK);
		use_forks(philo->right, philo, R_FORK);
	}
	else if (turn == 2)
	{
		use_forks(philo->right, philo, R_FORK);
		use_forks(philo->left, philo, L_FORK);
	}
	else
	{
		use_forks(philo->left, philo, L_FORK);
		sleep_ms(philo->global->time_to_die + 1);
		check_time_to_die(philo);
	}
}
