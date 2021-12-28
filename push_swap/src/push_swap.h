/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:29:17 by ioriola           #+#    #+#             */
/*   Updated: 2021/10/18 07:43:21 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

# include <libft.h>

typedef struct s_stack_node{
	int					value;
	int					index;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack{
	t_stack_node	*head;
	int				size;
	char			name;
}	t_stack;

typedef struct s_all{
	char	**args;
	t_stack	*a;
	t_stack	*b;
	int		total_values;
}	t_all;

// main.c //
short			check_args(char **argv);
int				goodbye(int failure, t_all *all);

// free_memory.c //
void			free_stacks(t_all *all);
void			free_stack_a(t_all *all);
void			free_stack_b(t_all *all);
void			free_args(int elements, t_all *all);

// init_values.c /
void			init_values(t_all *all);
t_stack			*init_stack(t_all *all, char name);

// operations1.c //
void			sab(t_stack *stack);
void			ss(t_stack *stack1, t_stack *stack2);
void			pab(t_stack *stack_from, t_stack *stack_to);

// operations2.c //
void			rab(t_stack *stack);
void			rr(t_stack *stack1, t_stack *stack2);
void			rrab(t_stack *stack);
void			rrr(t_stack *stack1, t_stack *stack2);

// sort_big_stack.c //
void			sort_big_stack(t_all *all);

// sort_small_stack.c //
void			sort_small_stack(t_all *all);
void			sort_2_elements(t_stack *stack);
void			sort_3_elements(t_stack *stack);
void			sort_3_elements2(int a, int b, int c, t_stack *stack);

// sort_small_stack2.c //
void			sort_4_elements(t_stack *stack1, t_stack *stack2, t_all *all);
void			sort_5_elements(t_stack *stack1, t_stack *stack2, t_all *all);

// solve.c //
void			solve(t_all *all);
t_stack_node	*get_next_min(t_stack *stack);
void			set_indexes(t_all *all);

// stacks_tools1.c //
void			add_node(int value, t_stack *stack);
void			copy_args_to_stack(int argc, char **argv, t_all *all);
short			number_is_in_stack(int nbr, t_stack *stack);
int				stack_is_sorted(t_stack *stack);

// stacks_tools2.c //
int				lowest_index_in_stack(t_stack *stack, t_all *all);
int				position_in_stack(int index, t_stack *stack);
void			move_index_to_top(int index, t_stack *stack);
void			split_n_copy(char *str, t_all *all);
void			just_copy(char *str, t_all *all);

// tools.c //
short			ft_isspace(char c);
long int		ft_atoli(const char *str);
short			has_spaces(char *str);
int				elements_in_str(char *str);
void			append(char *str, char c);

#endif
