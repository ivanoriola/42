/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_pthreads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 08:20:19 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/20 08:26:04 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_pthreads(t_global *global, t_philo **philo_list)
{
	int	i;

	i = 0;
	while (i < global->num_of_philos)
	{
		pthread_join(philo_list[i]->thread_id, NULL);
		i++;
	}
}
