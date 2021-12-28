/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:47:51 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/28 08:29:12 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// Rotate Stack - Shift up all elements of stack 'stack' by 1. 
// The first element becomes the last one.
void	rab(t_stack *stack)
{
	t_stack_node	*tmp_first;
	t_stack_node	*tmp_last;
	t_stack_node	*temp;

	temp = stack->head;
	if (!(temp && temp->next))
		return ;
	tmp_first = temp;
	temp = temp->next;
	tmp_last = temp;
	while (tmp_last->next)
	{
		tmp_last = tmp_last->next;
	}
	tmp_last->next = tmp_first;
	tmp_first->next = NULL;
	stack->head = temp;
}

// Rotate Stack - Shift up all elements of both stacks by 1. 
// The first element becomes the last one.
void	rr(t_stack *stack1, t_stack *stack2)
{
	rab(stack1);
	rab(stack2);
}

// Reverse rotate Stack - Shift down all elements of stack 'stack' by 1. 
// The last element becomes the first one.
void	rrab(t_stack *stack)
{
	t_stack_node	*tmp_last;
	t_stack_node	*previous;
	t_stack_node	*temp;

	temp = stack->head;
	if (!(temp && temp->next))
		return ;
	tmp_last = temp;
	while (tmp_last->next)
	{
		previous = tmp_last;
		tmp_last = tmp_last->next;
	}
	tmp_last->next = temp;
	previous->next = NULL;
	stack->head = tmp_last;
}

// Reverse rotate Stack - Shift down all elements of both stacks by 1. 
// The last element becomes the first one.
void	rrr(t_stack *stack1, t_stack *stack2)
{
	rrab(stack1);
	rrab(stack2);
}
