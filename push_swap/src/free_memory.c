/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 10:38:10 by ivanoriola        #+#    #+#             */
/*   Updated: 2021/10/18 07:52:43 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_stacks(t_all *all)
{
	free_stack_a(all);
	free_stack_b(all);
}

void	free_stack_a(t_all *all)
{
	t_stack_node	*current;
	t_stack_node	*delete;

	if (all->a->head)
	{
		current = all->a->head;
		while (current)
		{
			delete = current;
			current = current->next;
			free(delete);
		}
	}
	if (all->a)
		free(all->a);
}

void	free_stack_b(t_all *all)
{
	t_stack_node	*current;
	t_stack_node	*delete;

	if (all->b->head)
	{
		current = all->b->head;
		while (current)
		{
			delete = current;
			current = current->next;
			free(delete);
		}
	}
	if (all->b)
		free(all->b);
}

void	free_args(int elements, t_all *all)
{
	int	i;

	i = 0;
	if (all->args)
	{
		while (i < elements)
			free(all->args[i++]);
		free(all->args);
	}
}
