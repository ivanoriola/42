/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanoriola <ivanoriola@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:15:16 by ioriola           #+#    #+#             */
/*   Updated: 2021/10/05 16:59:54 by ivanoriola       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_small_stack(t_all *all)
{
	if (all->a->size == 2)
		sort_2_elements(all->a);
	else if (all->a->size == 3)
		sort_3_elements(all->a);
	else if (all->a->size == 4)
		sort_4_elements(all->a, all->b, all);
	else if (all->a->size == 5)
		sort_5_elements(all->a, all->b, all);
}

void	sort_2_elements(t_stack *stack)
{
	if (!stack_is_sorted(stack))
	{
		printf("s%c\n", stack->name);
		sab(stack);
	}
}

void	sort_3_elements(t_stack *stack)
{
	int				a;
	int				b;
	int				c;

	a = stack->head->value;
	b = stack->head->next->value;
	c = stack->head->next->next->value;
	if (a > b && a < c && b < c)
	{
		printf("s%c\n", stack->name);
		sab(stack);
	}
	if (a > b && a > c && b > c)
	{
		printf("s%c\n", stack->name);
		sab(stack);
		printf("rr%c\n", stack->name);
		rrab(stack);
	}
	sort_3_elements2(a, b, c, stack);
}

void	sort_3_elements2(int a, int b, int c, t_stack *stack)
{
	if (a > b && a > c && b < c)
	{
		printf("r%c\n", stack->name);
		rab(stack);
	}
	if (a < b && a < c && b > c)
	{
		printf("s%c\n", stack->name);
		sab(stack);
		printf("r%c\n", stack->name);
		rab(stack);
	}
	if (a < b && a > c && b > c)
	{
		printf("rr%c\n", stack->name);
		rrab(stack);
	}
}
