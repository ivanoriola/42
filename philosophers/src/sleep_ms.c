/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_ms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:42:56 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/20 07:43:05 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	sleep_ms(int time)
{
	t_time	stop_time;

	stop_time = get_time() + time;
	while (get_time() < stop_time)
		usleep(500);
}
