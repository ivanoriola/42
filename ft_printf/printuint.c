/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printuint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:04:53 by ioriola           #+#    #+#             */
/*   Updated: 2020/09/15 12:18:56 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			minus(t_struct *set, unsigned nbr, char *zeros, int size)
{
	if (nbr < 0)
	{
		if (zeros)
		{
			ft_putchar('-');
			ft_putstr(zeros);
		}
		else
		{
			ft_putstr(zeros);
			ft_putchar('-');
		}
		nbr *= -1;
	}
	else
		ft_putstr(zeros);
	if (size)
		ft_putuint(nbr);
	printzerosspaces(set, size);
	set->counter += size;
}

void			nominus(t_struct *set, unsigned nbr, char *zeros, int size)
{
	if (nbr < 0)
	{
		if (set->fzero)
		{
			ft_putchar('-');
			printzerosspaces(set, size);
		}
		else
		{
			printzerosspaces(set, size);
			ft_putchar('-');
		}
		nbr *= -1;
	}
	else
		printzerosspaces(set, size);
	ft_putstr(zeros);
	if (size)
		ft_putuint(nbr);
	set->counter += size;
}

void			doitnbr(t_struct *set, unsigned nbr, char *zeros, int size)
{
	if (set->fminus)
	{
		minus(set, nbr, zeros, size);
	}
	else
	{
		nominus(set, nbr, zeros, size);
	}
}

void			printuint(t_struct *set)
{
	unsigned	nbr;
	char		*zeros;
	int			size;

	nbr = (unsigned)va_arg(set->varg, int);
	zeros = "";
	size = digit_u_count(nbr, 10);
	if (set->fprec == 0)
		size = 0;
	if (set->fprec > 0)
	{
		while (set->fprec-- > size)
		{
			zeros = ft_strjoin(zeros, "0");
			set->counter++;
			set->fwidth--;
			free(zeros);
		}
	}
	doitnbr(set, nbr, zeros, size);
}
