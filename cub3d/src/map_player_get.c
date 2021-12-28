/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_player_get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:12:36 by ivanoriola        #+#    #+#             */
/*   Updated: 2021/09/16 10:47:34 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	get_map(t_all *all, char *line)
{
	line = line_spaces_at_end(line, all->map.width);
	all->map.map[all->map.rows] = ft_strdup(line);
	free(line);
	all->map.rows++;
}

char	*line_spaces_at_end(char *line, int width)
{
	int		i;
	int		j;
	int		difference;
	char	*clean;

	i = (int) ft_strlen(line);
	difference = width - i;
	clean = (char *) malloc(difference + 1);
	j = 0;
	while (j < difference)
	{
		clean[j] = ' ';
		j++;
	}
	clean[j] = '\0';
	line = ft_strjoin(line, clean);
	free (clean);
	return (line);
}

void	get_player_initial_pos_and_dir(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->map.height)
	{
		x = 0;
		while (all->map.map[y][x])
		{
			if (char_is_player(all->map.map[y][x]))
			{
				all->player.x = x;
				all->player.y = y;
				get_player_dir(all, all->map.map[y][x]);
				all->map.map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
	goodbye(all, "Error\nPLAYER MISSING");
}

int	char_is_player(char c)
{
	if (c == 'N' || c == 'S'
		|| c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

void	get_player_dir(t_all *all, char c)
{
	if (c == 'N')
		all->player.dir = DIR_UP;
	if (c == 'S')
		all->player.dir = DIR_DOWN;
	if (c == 'W')
		all->player.dir = DIR_LEFT;
	if (c == 'E')
		all->player.dir = DIR_RIGHT;
}
