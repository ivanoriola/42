/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:45:56 by ioriola           #+#    #+#             */
/*   Updated: 2021/10/05 12:23:01 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	solve(t_all *all)
{
	if (stack_is_sorted(all->a))
		goodbye(EXIT_SUCCESS, all);
	set_indexes(all);
	if (all->a->size <= 5)
		sort_small_stack(all);
	else
		sort_big_stack(all);
}

t_stack_node	*get_next_min(t_stack *stack)
{
	int				i;
	short			has_min;
	t_stack_node	*min;
	t_stack_node	*current;

	min = NULL;
	if (stack)
	{
		i = 0;
		has_min = 0;
		current = stack->head;
		while (i < stack->size)
		{
			if ((current->index == -1)
				&& (!has_min || current->value < min->value))
			{
				has_min = 1;
				min = current;
			}
			i++;
			current = current->next;
		}
	}
	return (min);
}

void	set_indexes(t_all *all)
{
	int				index;
	t_stack_node	*current;

	index = 0;
	current = get_next_min(all->a);
	while (current)
	{
		current->index = index++;
		current = get_next_min(all->a);
	}
}
