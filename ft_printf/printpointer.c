/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 11:04:07 by ioriola           #+#    #+#             */
/*   Updated: 2020/09/15 12:21:53 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			doitp(t_struct *set, char *hexnbr, char *zeros, int size)
{
	size += 2;
	if (set->fminus)
	{
		ft_putstr("0x");
		ft_putstr(zeros);
		if (size != 2)
			ft_putstr(hexnbr);
		printzerosspaces(set, size);
	}
	else
	{
		printzerosspaces(set, size);
		ft_putstr("0x");
		ft_putstr(zeros);
		if (size != 2)
			ft_putstr(hexnbr);
	}
	set->counter += size;
	free(hexnbr);
}

static void			predoitp(t_struct *set, char *hexnbr, char *zeros, int size)
{
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
	doitp(set, hexnbr, zeros, size);
}

void				printpointer(t_struct *set)
{
	unsigned long	nbr;
	char			*hexnbr;
	char			*zeros;
	int				size;

	if (!(nbr = va_arg(set->varg, unsigned long)))
		hexnbr = ft_strdup("0");
	else
		hexnbr = ft_itoa_base_pointer(nbr, 16);
	if (hexnbr[0] == '\0')
	{
		hexnbr[0] = '0';
		hexnbr[1] = '\0';
	}
	zeros = "";
	size = ft_strlen(hexnbr);
	predoitp(set, hexnbr, zeros, size);
}
