/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:50:01 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/21 07:48:33 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**init_philo_list(t_global	*global)
{
	int		i;
	t_philo	**philo_list;

	i = 0;
	philo_list = malloc((sizeof(t_philo *) * (global->num_of_philos + 1)));
	if (!philo_list)
		return (NULL);
	while (i < global->num_of_philos)
	{
		philo_list[i] = (t_philo *)malloc(sizeof(t_philo));
		if (!(philo_list[i]))
			return (NULL);
		philo_list[i]->position = i + 1;
		philo_list[i]->global = global;
		philo_list[i]->state = -1;
		philo_list[i]->num_of_eat = 0;
		i++;
	}
	philo_list[i] = NULL;
	return (philo_list);
}
