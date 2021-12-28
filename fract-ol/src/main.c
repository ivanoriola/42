/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:33:04 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/23 07:53:56 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	main(int argc, char **argv)
{
	t_all	all;

	init_values(&all);
	if (argc > 3 || argc == 1 || !arg_ok(&all, argv[1]))
	{
		goodbye(&all, "\n\'fractol J\' Julia set\n\'fractol M\' Mandelbrot set");
	}
	reset_values(&all);
	init_window(&all);
	setup(&all);
	update(&all);
	render(&all);
	mlx_key_hook (all.mlx.win_ptr, key_hook, &all);
	mlx_mouse_hook (all.mlx.win_ptr, mouse_hook, &all);
	mlx_hook(all.mlx.win_ptr, 17, 0L, goodbye, &all);
	mlx_loop(all.mlx.mlx_ptr);
	return (0);
}

int	arg_ok(t_all *all, char *str)
{
	if (ft_strlen(str) == 1
		&& (str[0] == 'J' || str[0] == 'j' || str[0] == 'M' || str[0] == 'm'))
	{
		all->fr.set_type = ft_toupper(str[0]);
		return (1);
	}
	return (0);
}

int	goodbye(t_all *all, char *errmsg)
{
	free_memory(all);
	if (all->mlx.win_ptr)
		mlx_destroy_window(all->mlx.mlx_ptr, all->mlx.win_ptr);
	printf ("%s", errmsg);
	exit(EXIT_SUCCESS);
}

void	free_memory(t_all *all)
{
	if (all->mlx.co_buff)
		free(all->mlx.co_buff);
}
