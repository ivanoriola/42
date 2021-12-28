/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 09:43:33 by ioriola           #+#    #+#             */
/*   Updated: 2020/09/15 09:30:44 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	setalltozero(t_struct *set)
{
	set->text = "";
	set->index = 0;
	set->type = 0;
	set->fminus = 0;
	set->fprec = -1;
	set->precstar = 0;
	set->fwidth = 0;
	set->widthstar = 0;
	set->fzero = 0;
	set->counter = 0;
	set->error = 0;
}

void	setsometozero(t_struct *set)
{
	set->type = 0;
	set->fminus = 0;
	set->fprec = -1;
	set->precstar = 0;
	set->fwidth = 0;
	set->widthstar = 0;
	set->fzero = 0;
	set->error = 0;
}

void	printzerosspaces(t_struct *set, int size)
{
	if (set->fwidth)
	{
		while (set->fwidth > size)
		{
			if (set->fzero)
				ft_putchar('0');
			else
				ft_putchar(' ');
			set->counter++;
			set->fwidth--;
		}
	}
}

void	ft_putlong(long nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putlong(nb * (-1));
	}
	else
	{
		if (nb >= 10)
			ft_putlong(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

void	ft_putuint(unsigned int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putuint(nb * (-1));
	}
	else
	{
		if (nb >= 10)
			ft_putuint(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}
