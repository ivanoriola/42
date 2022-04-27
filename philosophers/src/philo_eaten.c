/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eaten.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:50:39 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/21 08:53:27 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_eaten(t_global *global, t_philo **philo_list)
{
	int	i;

	i = 0;
	while (i < global->num_of_philos)
	{
		if (philo_list[i]->state != DEAD)
		{
			if (philo_list[i]->num_of_eat != global->num_of_must_eat)
				return (0);
		}
		i++;
	}
	return (1);
}
