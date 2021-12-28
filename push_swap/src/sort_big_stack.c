/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanoriola <ivanoriola@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:15:16 by ioriola           #+#    #+#             */
/*   Updated: 2021/10/05 16:58:58 by ivanoriola       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	in_while_process(int i, t_all *all)
{
	int	num;

	num = all->a->head->index;
	if ((num >> i) & 1)
	{
		printf("r%c\n", all->a->name);
		rab(all->a);
	}
	else
	{
		printf("p%c\n", all->b->name);
		pab(all->a, all->b);
	}
}

void	sort_big_stack(t_all *all)
{
	int	max_num;
	int	max_bits;
	int	i;
	int	j;

	max_num = all->total_values - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < all->total_values)
		{
			in_while_process(i, all);
			j++;
		}
		while (all->b->head)
		{
			printf("p%c\n", all->a->name);
			pab(all->b, all->a);
		}
		i++;
	}
}
