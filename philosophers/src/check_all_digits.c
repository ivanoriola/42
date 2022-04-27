/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all_digits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:43:44 by ioriola           #+#    #+#             */
/*   Updated: 2022/04/20 09:54:18 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_all_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
