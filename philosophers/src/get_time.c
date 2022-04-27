/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:37:34 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/20 08:01:28 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_time	get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((t_time)(current_time.tv_sec * 1000 + current_time.tv_usec / 1000));
}
