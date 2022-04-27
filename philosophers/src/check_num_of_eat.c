/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_of_eat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 08:38:51 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/21 09:59:43 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_num_of_eat(t_global *global, t_philo **philo_list)
{
	if (philo_eaten(global, philo_list))
	{
		if (!(global->dead))
			printf(WHITE "\nPhilosophers have finished eaten");
	}
}
