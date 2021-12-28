/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:01:20 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/23 07:55:30 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int	init_window(t_all *all)
{
	all->mlx.mlx_ptr = mlx_init();
	if (!all->mlx.mlx_ptr)
		goodbye(all, "Error\nINITIALIZING MLX");
	all->mlx.win_ptr = mlx_new_window(all->mlx.mlx_ptr,
			all->mlx.xres, all->mlx.yres, "Fractol");
	if (!all->mlx.win_ptr)
		goodbye (all, "Error\nCREATING WINDOW");
	return (1);
}

int	key_hook(int key, t_all *all)
{
	if (key == ESC)
		goodbye (all, "\nGood Bye!");
	else if (key == R)
		reset_values(all);
	else if (key == W)
		all->fr.imag -= 0.02 / all->fr.zoom;
	else if (key == S)
		all->fr.imag += 0.02 / all->fr.zoom;
	else if (key == A)
		all->fr.real -= 0.02 / all->fr.zoom;
	else if (key == D)
		all->fr.real += 0.02 / all->fr.zoom;
	else if (key == UP)
		all->fr.movey += 0.25 / all->fr.zoom;
	else if (key == DOWN)
		all->fr.movey -= 0.25 / all->fr.zoom;
	else if (key == LEFT)
		all->fr.movex += 0.25 / all->fr.zoom;
	else if (key == RIGHT)
		all->fr.movex -= 0.25 / all->fr.zoom;
	update(all);
	render(all);
	return (1);
}

int	mouse_hook(int button, int x, int y, t_all *all)
{
	int	mouse_x;
	int	mouse_y;

	mouse_x = x;
	mouse_y = y;
	if (button == 1)
		all->fr.max_iter += 50;
	else if (button == 2)
		all->fr.max_iter -= 50;
	else if (button == 4)
		all->fr.zoom *= 1.25;
	else if (button == 5)
		all->fr.zoom /= 1.25;
	update(all);
	render(all);
	return (1);
}
