/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 09:41:19 by ioriola           #+#    #+#             */
/*   Updated: 2020/09/15 10:34:47 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	withminus(t_struct *set, long nbr, char *zeros, int size)
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
		ft_putlong(nbr);
	printzerosspaces(set, size);
	set->counter += size;
}

static void	withoutminus(t_struct *set, long nbr, char *zeros, int size)
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
		ft_putlong(nbr);
	set->counter += size;
}

static void	doitnbr(t_struct *set, long nbr, char *zeros, int size)
{
	if (set->fminus)
	{
		withminus(set, nbr, zeros, size);
	}
	else
	{
		withoutminus(set, nbr, zeros, size);
	}
}

void		printint(t_struct *set)
{
	long	nbr;
	char	*zeros;
	int		size;

	nbr = (long)va_arg(set->varg, int);
	zeros = "";
	size = digit_count(nbr, 10);
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
	if (nbr < 0)
		size++;
	doitnbr(set, nbr, zeros, size);
}
