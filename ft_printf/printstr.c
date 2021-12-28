/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 10:43:53 by ioriola           #+#    #+#             */
/*   Updated: 2020/09/15 09:31:27 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printstr(t_struct *set)
{
	char	*str;
	char	*tempstr;
	int		size;

	if (!(str = va_arg(set->varg, char*)))
		tempstr = ft_strdup("(null)");
	else
		tempstr = ft_strdup(str);
	if ((set->fprec >= 0) && (set->fprec < (int)ft_strlen(tempstr)))
		tempstr[set->fprec] = '\0';
	size = ft_strlen(tempstr);
	if (set->fminus)
	{
		ft_putstr(tempstr);
		printzerosspaces(set, size);
	}
	else
	{
		printzerosspaces(set, size);
		ft_putstr(tempstr);
	}
	set->counter += size;
	free(tempstr);
}
