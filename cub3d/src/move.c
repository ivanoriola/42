/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 09:41:19 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/07 09:05:48 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	move_front(t_all *all, int direction)
{
	if (all->player.dir == DIR_UP)
		all->player.y -= direction;
	if (all->player.dir == DIR_RIGHT)
		all->player.x += direction;
	if (all->player.dir == DIR_DOWN)
		all->player.y += direction;
	if (all->player.dir == DIR_LEFT)
		all->player.x -= direction;
	val_limit_adjust(all);
	if (map_xy_content(all, all->player.x, all->player.y) == '1')
		move_front (all, (-1 * direction));
}

void	move_side(t_all *all, int direction)
{
	if (all->player.dir == DIR_UP)
		all->player.x -= direction;
	if (all->player.dir == DIR_RIGHT)
		all->player.y -= direction;
	if (all->player.dir == DIR_DOWN)
		all->player.x += direction;
	if (all->player.dir == DIR_LEFT)
		all->player.y += direction;
	val_limit_adjust(all);
	if (map_xy_content(all, all->player.x, all->player.y) == '1')
		move_side (all, (-1 * direction));
}

void	turn(t_all *all, int direction)
{
	all->player.dir += (QUARTER * direction);
	val_limit_adjust(all);
}

void	val_limit_adjust(t_all *all)
{
	if (all->player.x < 0)
		all->player.x = 0;
	if (all->player.x >= all->map.width)
		all->player.x = all->map.width - 1;
	if (all->player.y < 0)
		all->player.y = 0;
	if (all->player.y >= all->map.height)
		all->player.y = all->map.height - 1;
	if (all->player.dir < DIR_RIGHT)
		all->player.dir = DIR_UP;
	if (all->player.dir == FULL)
		all->player.dir = DIR_RIGHT;
	if (all->player.dir > FULL)
		all->player.dir = DIR_DOWN;
}

int	map_xy_content(t_all *all, int x, int y)
{
	int	map_grid_index_x;
	int	map_grid_index_y;

	if (x < 0 || x > all->map.width || y < 0 || y > all->map.height)
	{
		return ('1');
	}
	map_grid_index_x = floor(x / all->map.til_siz);
	map_grid_index_y = floor(y / all->map.til_siz);
	return (all->map.map[map_grid_index_y][map_grid_index_x]);
}
