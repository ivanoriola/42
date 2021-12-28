/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:01:20 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/14 11:29:37 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	init_window(t_all *all)
{
	int		w;
	int		h;
	char	*title;

	w = all->settings.xres;
	h = all->settings.yres;
	title = all->map.file_name;
	all->mlx.mlx_ptr = mlx_init();
	if (!all->mlx.mlx_ptr)
		goodbye(all, "Error\nINITIALIZING MLX");
	all->mlx.win_ptr = mlx_new_window(all->mlx.mlx_ptr, w, h, title);
	if (!all->mlx.win_ptr)
		goodbye (all, "Error\nCREATING WINDOW");
	return (1);
}

int	key_hook(int key, t_all *all)
{
	if (key == ESC)
		goodbye (all, "Good Bye!");
	else if (key == W)
		move_front(all, 1);
	else if (key == S)
		move_front(all, -1);
	else if (key == A)
		move_side(all, 1);
	else if (key == D)
		move_side(all, -1);
	else if (key == LEFT)
		turn(all, -1);
	else if (key == RIGHT)
		turn(all, 1);
	update(all);
	render(all);
	return (1);
}
