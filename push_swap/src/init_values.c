/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanoriola <ivanoriola@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 07:53:20 by ioriola           #+#    #+#             */
/*   Updated: 2021/10/03 10:30:29 by ivanoriola       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	init_values(t_all *all)
{
	all->a = init_stack(all, 'a');
	all->b = init_stack(all, 'b');
}

t_stack	*init_stack(t_all *all, char name)
{
	t_stack	*stack;

	stack = (t_stack *) malloc(sizeof(t_stack));
	if (!stack)
		goodbye(EXIT_FAILURE, all);
	stack->head = NULL;
	stack->size = 0;
	stack->name = name;
	return (stack);
}
