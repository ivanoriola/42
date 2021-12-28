/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 10:57:50 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/08 11:39:28 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts the initial portion of the string
** pointed to by 'str' to int representation.
*/

static int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	else if (c == ' ' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int				ft_atoi(const char *str)
{
	long int	nbr;
	int			negative;

	nbr = 0;
	negative = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	while (ft_isdigit(*str))
	{
		nbr *= 10;
		nbr -= ((int)*str - '0');
		str++;
	}
	return ((int)negative * nbr);
}
