/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 08:30:40 by ioriola           #+#    #+#             */
/*   Updated: 2020/09/15 11:19:51 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Produces output under the control of a format string that
** specifies how subsequent arguments are converted for output.
** Writes output to stdout (the standard output stream)
** Returns the number of characters printed (not including
** the trailing `\0'), or a negative value if an error occurs.
*/

void		kernel(t_struct *set)
{
	while (set->text[set->index] != '\0')
	{
		if (set->text[set->index] == '%')
		{
			setsometozero(set);
			set->block = getblock(set);
			processblock(set);
			free(set->block);
		}
		else
		{
			write(1, &set->text[set->index], 1);
			set->counter++;
		}
		set->index++;
	}
}

char		*getblock(t_struct *set)
{
	int		blockinit;
	int		blockend;
	int		blocklen;
	char	*block;

	blockinit = set->index++;
	blockend = blockinit;
	while (isflag(set->text[set->index]) || ft_isdigit(set->text[set->index]))
		set->index++;
	if (istype(set->text[set->index]))
	{
		blockend = set->index;
		blocklen = blockend - blockinit + 1;
		block = ft_strdup(&set->text[blockinit]);
		block[blocklen] = '\0';
		set->type = block[blocklen - 1];
		return (block);
	}
	else
	{
		set->index = blockend;
		return (NULL);
	}
}

void		processblock(t_struct *set)
{
	if (set->block == NULL)
		set->error++;
	else
	{
		getprecision(set);
		getwidth(set);
		getflags(set);
		if (set->widthstar == 1)
		{
			set->fwidth = va_arg(set->varg, int);
			if (set->fwidth < 0)
			{
				set->fwidth *= -1;
				set->fminus = 1;
				set->fzero = 0;
			}
		}
		if (set->precstar == 1)
		{
			set->fprec = va_arg(set->varg, int);
			if (set->fprec < 0)
				set->fprec = -1;
		}
		printwhatever(set);
	}
}

void		printwhatever(t_struct *set)
{
	if (set->type == 'c' || set->type == '%')
		printchar(set);
	if (set->type == 's')
		printstr(set);
	if (set->type == 'p')
		printpointer(set);
	if (set->type == 'd' || set->type == 'i')
		printint(set);
	if (set->type == 'u')
		printuint(set);
	if (set->type == 'x' || set->type == 'X')
		printhex(set);
}

int			ft_printf(const char *text, ...)
{
	t_struct	*set;

	if (!(set = (t_struct *)malloc(sizeof(t_struct))))
		return (-1);
	va_start(set->varg, text);
	setalltozero(set);
	if (!(set->text = ft_strdup(text)))
		return (-1);
	kernel(set);
	va_end(set->varg);
	if (set->error != 0)
		set->counter = -1;
	free(set->text);
	free(set);
	return (set->counter);
}
