/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:08:18 by ioriola           #+#    #+#             */
/*   Updated: 2021/10/07 07:28:02 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	lowest_index_in_stack(t_stack *stack, t_all *all)
{
	int				min;
	t_stack_node	*temp;

	min = all->total_values;
	temp = stack->head;
	while (temp)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}

int	position_in_stack(int index, t_stack *stack)
{
	int				position;
	t_stack_node	*temp;

	position = 0;
	temp = stack->head;
	while (temp)
	{
		if (temp->index == index)
			return (position);
		temp = temp->next;
		position++;
	}
	return (-1);
}

void	move_index_to_top(int index, t_stack *stack)
{
	while (stack->head->index != index)
	{
		if (position_in_stack(index, stack)
			<= stack->size / 2)
		{
			printf("r%c\n", stack->name);
			rab(stack);
		}
		else
		{
			printf("rr%c\n", stack->name);
			rrab(stack);
		}
	}
}

void	split_n_copy(char *str, t_all *all)
{
	int		element;
	int		elements;
	int		i;

	elements = elements_in_str(str);
	if (!elements)
		return ;
	all->args = (char **) malloc (sizeof(char *) * (elements));
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	element = elements - 1;
	while (element >= 0)
	{
		all->args[element] = (char *) malloc (sizeof(char) * 12);
		while (!ft_isspace(str[i]) && str[i])
			append(all->args[element], str[i++]);
		while (ft_isspace(str[i]) && str[i])
			i++;
		element--;
	}
	element = 0;
	while (element < elements)
		just_copy(all->args[element++], all);
	free_args(elements, all);
}

void	just_copy(char *str, t_all *all)
{
	long int	nbr;

	if (str[0] == 0)
		return ;
	nbr = ft_atoli(str);
	if (nbr < -2147483648 || nbr > 2147483647)
		goodbye(EXIT_FAILURE, all);
	nbr = ft_atoi(str);
	if (number_is_in_stack((int) nbr, all->a))
		goodbye(EXIT_FAILURE, all);
	else
	{
		add_node((int) nbr, all->a);
		all->a->size++;
	}
}
