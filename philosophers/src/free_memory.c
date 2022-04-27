/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 09:06:41 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/21 08:42:33 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_memory(t_global *global, t_philo **philo_list)
{
	int	i;

	free(global->mutex_list);
	free(global->mutex_print);
	i = global->num_of_philos;
	while (i > -1)
	{
		free(philo_list[i]);
		i--;
	}
	free(philo_list);
}
