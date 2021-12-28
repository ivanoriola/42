/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 08:47:17 by ioriola           #+#    #+#             */
/*   Updated: 2020/09/15 12:04:15 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		getprecision(t_struct *set)
{
	char	*precision;
	char	*end;
	char	*blockcopy;

	blockcopy = ft_strdup(set->block);
	if ((precision = ft_strrchr(blockcopy, '.')))
	{
		precision++;
		end = ft_strrchr(blockcopy, set->type);
		end[0] = '\0';
		if (ft_strrchr(precision, '*'))
			set->precstar = 1;
		else
			set->fprec = ft_atoi(precision);
	}
	free(blockcopy);
}

void		getwidth2(char *blockcopy, int i, t_struct *set)
{
	char	*width;

	width = &blockcopy[i];
	while (ft_isdigit(blockcopy[i]))
		i++;
	blockcopy[i] = '\0';
	set->fwidth = ft_atoi(width);
	free(blockcopy);
}

void		getwidth(t_struct *set)
{
	int		i;
	char	*blockcopy;

	blockcopy = ft_strdup(set->block);
	i = 1;
	while (isflag(blockcopy[i]))
	{
		if (blockcopy[i] == '*')
		{
			set->widthstar = 1;
			free(blockcopy);
			return ;
		}
		if (blockcopy[i] == '.' || istype(blockcopy[i]))
		{
			set->fwidth = 0;
			free(blockcopy);
			return ;
		}
		i++;
	}
	getwidth2(blockcopy, i, set);
}

void		getflags(t_struct *set)
{
	int		i;

	set->fzero = 0;
	set->fminus = ft_strchr(set->block, '-') ? 1 : 0;
	i = 0;
	while (!ft_isdigit(set->block[i]) && set->block[i])
	{
		i++;
	}
	if (set->block[i] == '0' && !set->fminus)
	{
		if (!((set->fprec >= 0) &&
		(set->type == 'i' || set->type == 'u' ||
		set->type == 'x' || set->type == 'X' || set->type == 'd')))
			set->fzero = 1;
	}
}
