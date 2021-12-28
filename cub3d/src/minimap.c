/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 18:12:58 by ivanoriola        #+#    #+#             */
/*   Updated: 2021/09/15 10:06:21 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_sqr(int x, int y, int color, t_all *all)
{
	int	i;
	int	j;
	int	pix_margin;

	pix_margin = 0;
	i = pix_margin;
	while (i < (all->map.til_map - pix_margin))
	{
		j = pix_margin;
		while (j < (all->map.til_map - pix_margin))
		{
			mlx_pixel_put(all->mlx.mlx_ptr, all->mlx.win_ptr,
				(x + i), (y + j), color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(char	**map, t_all *all)
{
	int	i;
	int	j;
	int	color;

	i = all->player.y - all->map.mrg;
	while (i < all->player.y + all->map.mrg)
	{
		j = all->player.x - all->map.mrg;
		while (j < all->player.x + all->map.mrg)
		{
			color = BLACK;
			if (i >= 0 && i < all->map.height && j >= 0 && j < all->map.width)
			{
				if (map[i][j] == '0')
					color = BLACK;
				else if (map[i][j] == '1')
					color = WHITE;
			}
			draw_sqr((j - all->player.x + all->map.mrg) * all->map.til_map,
				(i - all->player.y + all->map.mrg) * all->map.til_map,
				color, all);
			j++;
		}
		i++;
	}
}

void	draw_player(t_all *all)
{
	int		i;
	int		j;
	char	*player_dir;

	i = all->map.mrg;
	j = all->map.mrg;
	if (all->player.dir == DIR_UP)
		player_dir = "N";
	if (all->player.dir == DIR_DOWN)
		player_dir = "S";
	if (all->player.dir == DIR_LEFT)
		player_dir = "W";
	if (all->player.dir == DIR_RIGHT)
		player_dir = "E";
	mlx_string_put(all->mlx.mlx_ptr, all->mlx.win_ptr,
		(i * all->map.til_map) - 2, (j * all->map.til_map) + 7,
		RED, player_dir);
}
