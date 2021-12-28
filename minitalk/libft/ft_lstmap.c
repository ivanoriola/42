/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 10:23:27 by ioriola           #+#    #+#             */
/*   Updated: 2021/05/19 10:48:59 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Iterates the list ’lst’ and applies the function
** ’f’ to the content of each element. Creates a new
** list resulting of the successive applications of
** the function ’f’. The ’del’ function is used to
** delete the content of an element if needed.
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*next_old;
	t_list	*next_new;

	new_list = ft_lstnew((*f)(lst->content));
	if (!lst || !(new_list))
		return (NULL);
	next_new = new_list;
	next_old = lst->next;
	while (lst)
	{
		if (next_old == NULL)
			break ;
		next_new->next = ft_lstnew((*f)(next_old->content));
		if (!(next_new->next))
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		next_new = next_new->next;
		next_old = next_old->next;
	}
	return (new_list);
}
