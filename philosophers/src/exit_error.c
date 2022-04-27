/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 07:36:27 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/25 08:16:56 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exit_error(char const *str, int err_value)
{
	printf(LIGHTRED "\nError: " WHITE);
	printf("%s", str);
	return (err_value);
}
