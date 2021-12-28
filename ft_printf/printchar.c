/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 11:40:15 by ioriola           #+#    #+#             */
/*   Updated: 2020/09/15 09:31:27 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printchar(t_struct *set)
{
	char	c;
	int		size;

	size = 1;
	if (set->type == 'c')
		c = va_arg(set->varg, int);
	else if (set->type == '%')
		c = '%';
	if (set->fminus)
	{
		ft_putchar(c);
		set->counter++;
		printzerosspaces(set, size);
	}
	else
	{
		printzerosspaces(set, size);
		ft_putchar(c);
		set->counter++;
	}
}
