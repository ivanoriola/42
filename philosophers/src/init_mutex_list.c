/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:51:05 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/21 08:40:52 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex_list(t_global *global, t_philo	**philo_list)
{
	int	i;

	global->mutex_list = malloc(sizeof(pthread_mutex_t)
			* (global->num_of_philos));
	global->mutex_print = malloc(sizeof(pthread_mutex_t));
	if (!(global->mutex_list) || (!(global->mutex_print)))
		return (0);
	i = 0;
	while (i < global->num_of_philos)
	{
		if (i == 0)
			philo_list[i]->left
				= &global->mutex_list[global->num_of_philos - 1];
		else
			philo_list[i]->left = &global->mutex_list[i - 1];
		philo_list[i]->right = &global->mutex_list[i];
		pthread_mutex_init(&global->mutex_list[i], NULL);
		i++;
	}
	pthread_mutex_init(global->mutex_print, NULL);
	return (1);
}
