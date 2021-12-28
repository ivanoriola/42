/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:02:58 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/08 09:16:11 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Adds the element ’new’ at the beginning of the
** list.
*/

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (*alst)
		new->next = *alst;
	*alst = new;
}
