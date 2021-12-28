/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_tools1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:58:44 by ioriola           #+#    #+#             */
/*   Updated: 2021/10/05 11:56:22 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	add_node(int value, t_stack *stack)
{
	t_stack_node	*node;

	node = (t_stack_node *)malloc(sizeof(t_stack_node));
	node->value = value;
	node->index = -1;
	if (stack->head == NULL)
		node->next = NULL;
	else
		node->next = stack->head;
	stack->head = node;
}

void	copy_args_to_stack(int argc, char **argv, t_all *all)
{
	int			i;

	i = argc - 1;
	while (i > 0)
	{
		if (ft_strlen(argv[i]))
		{
			if (has_spaces(argv[i]))
				split_n_copy(argv[i], all);
			else
				just_copy(argv[i], all);
		}
		i--;
	}
	all->total_values = all->a->size;
}

short	number_is_in_stack(int nbr, t_stack *stack)
{
	t_stack_node	*temp;

	temp = stack->head;
	while (temp)
	{
		if (nbr == temp->value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	stack_is_sorted(t_stack *stack)
{
	t_stack_node	*temp;

	temp = stack->head;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}
