/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:02:58 by ioriola           #+#    #+#             */
/*   Updated: 2021/05/19 10:38:09 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
