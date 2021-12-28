/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:25:06 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/09 10:06:07 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Counts the number of elements in a list.
*/

int		ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		lst = lst->next;
		counter++;
	}
	return (counter);
}
