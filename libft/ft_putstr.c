/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 09:30:45 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/16 08:14:12 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string ’s’.
*/

void	ft_putstr(char *str)
{
	int	i;

	if (str)
	{
		i = 0;
		while (!(str[i] == '\0'))
		{
			ft_putchar(str[i]);
			i++;
		}
	}
}
