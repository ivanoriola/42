/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:12:59 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/28 08:28:55 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// Swap the first 2 elements at the top of 'stack'.
// Do nothing if there is only one or no elements).
void	sab(t_stack *stack)
{
	int				temp_value;
	t_stack_node	*temp;

	temp = stack->head;
	if (temp && temp->next)
	{
		temp_value = temp->value;
		temp->value = temp->next->value;
		temp->next->value = temp_value;
	}
}

// Swap the first 2 elements at the top of both stacks.
void	ss(t_stack *stack1, t_stack *stack2)
{
	sab(stack1);
	sab(stack2);
}

// Take the first element at the top of 'stack_from'
// and put it at the top of 'stack_to'. Do nothing if 'stack_from' is empty.
void	pab(t_stack *stack_from, t_stack *stack_to)
{
	t_stack_node	*tmp;
	t_stack_node	*to;
	t_stack_node	*from;

	to = stack_to->head;
	from = stack_from->head;
	if (!from)
		return ;
	tmp = from;
	from = from->next;
	stack_from->head = from;
	if (!to)
	{
		to = tmp;
		to->next = NULL;
		stack_to->head = to;
	}
	else
	{
		tmp->next = to;
		stack_to->head = tmp;
	}
	stack_from->size--;
	stack_to->size++;
}
