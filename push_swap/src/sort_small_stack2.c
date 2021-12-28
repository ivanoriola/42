/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 08:12:27 by ioriola           #+#    #+#             */
/*   Updated: 2021/10/06 08:11:31 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_4_elements(t_stack *stack1, t_stack *stack2, t_all *all)
{
	move_index_to_top(lowest_index_in_stack(stack1, all), stack1);
	if (stack_is_sorted(stack1))
		return ;
	else
	{
		printf("p%c\n", stack2->name);
		pab(stack1, stack2);
		sort_3_elements(stack1);
		printf("p%c\n", stack1->name);
		pab(stack2, stack1);
	}
}

void	sort_5_elements(t_stack *stack1, t_stack *stack2, t_all *all)
{
	move_index_to_top(lowest_index_in_stack(stack1, all), stack1);
	if (stack_is_sorted(stack1))
		return ;
	else
	{
		printf("p%c\n", stack2->name);
		pab(stack1, stack2);
		sort_4_elements(stack1, stack2, all);
		printf("p%c\n", stack1->name);
		pab(stack2, stack1);
	}
}
