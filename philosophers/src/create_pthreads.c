/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pthreads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:14:54 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/20 08:25:56 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_pthreads(t_global *global, t_philo **philo_list)
{
	int	i;

	i = 0;
	while (i < global->num_of_philos)
	{
		pthread_create(&philo_list[i]->thread_id, NULL,
			philo_thread, (void *)philo_list[i]);
		i++;
	}
}
