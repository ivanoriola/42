/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:28:46 by ioriola           #+#    #+#             */
/*   Updated: 2021/10/18 08:59:43 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_all	all;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	init_values(&all);
	if (argc > 1 && check_args(argv))
		copy_args_to_stack(argc, argv, &all);
	else
		goodbye(EXIT_FAILURE, &all);
	solve (&all);
	goodbye(EXIT_SUCCESS, &all);
}

short	check_args_in_while(char **argv, int i, int j)
{
	if (!has_spaces(argv[i]) && !ft_isdigit(argv[i][j]))
		return (0);
	if (has_spaces(argv[i]))
	{
		if ((argv[i][j] == '-' || argv[i][j] == '+')
			&& !ft_isdigit(argv[i][j + 1]))
			return (0);
		if (argv[i][j] != '-' && argv[i][j] != '+'
			&& !ft_isspace(argv[i][j]) && !ft_isdigit(argv[i][j]))
			return (0);
	}
	return (1);
}

short	check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if ((argv[i][j] == '-' || argv[i][j] == '+')
			&& !ft_isdigit(argv[i][j + 1]))
			return (0);
		if ((argv[i][j] == '-' || argv[i][j] == '+')
			&& ft_isdigit(argv[i][j + 1]))
			j++;
		while (argv[i][j])
		{
			if (!check_args_in_while(argv, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	goodbye(int failure, t_all *all)
{
	free_stacks(all);
	if (failure)
		write(2, "Error\n", 6);
	exit(failure);
}
