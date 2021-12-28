/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 11:08:23 by ioriola           #+#    #+#             */
/*   Updated: 2020/09/15 12:08:40 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			lowerxupperx(char type, char *str)
{
	int				i;

	i = 0;
	if (type == 'x')
	{
		while (str[i])
		{
			str[i] = ft_tolower(str[i]);
			i++;
		}
	}
	else if (type == 'X')
	{
		while (str[i])
		{
			str[i] = ft_toupper(str[i]);
			i++;
		}
	}
}

static void			doithex(t_struct *set, char *hexnbr, char *zeros, int size)
{
	if (set->fminus)
	{
		ft_putstr(zeros);
		if (size)
			ft_putstr(hexnbr);
		printzerosspaces(set, size);
		set->counter += size;
	}
	else
	{
		printzerosspaces(set, size);
		ft_putstr(zeros);
		if (size)
			ft_putstr(hexnbr);
		set->counter += size;
	}
	free(hexnbr);
}

void				printhex(t_struct *set)
{
	unsigned int	nbr;
	char			*hexnbr;
	char			*zeros;
	int				size;

	if (!(nbr = va_arg(set->varg, unsigned long)))
		hexnbr = ft_strdup("0");
	else
		hexnbr = ft_itoa_base_pointer(nbr, 16);
	lowerxupperx(set->type, hexnbr);
	zeros = "";
	size = ft_strlen(hexnbr);
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
	doithex(set, hexnbr, zeros, size);
}
