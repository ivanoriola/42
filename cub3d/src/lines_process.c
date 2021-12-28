/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 08:03:05 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/16 10:31:59 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	lines_map_count(int fd, t_all *all)
{
	char	*str;
	int		gnl;
	int		width;
	int		height;

	width = 0;
	height = 0;
	gnl = 1;
	while (gnl)
	{
		gnl = get_next_line(fd, &str);
		if (line_is_map(str))
		{
			if ((int) ft_strlen(str) > width)
				width = (int) ft_strlen(str);
			height++;
		}
		free (str);
	}
	all->map.width = width;
	all->map.height = height;
	all->map.map = (char **) malloc (sizeof (char *) * all->map.height);
	if (width != 0 && height != 0)
		all->settings.validate.map_ok = 1;
}

void	lines_get(int fd, t_all *all)
{
	char	*line;
	int		gnl;

	gnl = 1;
	while (gnl)
	{
		gnl = get_next_line(fd, &line);
		if (line_is_texture(line))
			get_textures(all, line, line_is_texture(line));
		else if (line_is_color(line))
			get_color(all, line, line_is_color(line));
		else if (line_is_map(line))
			get_map(all, line);
		free (line);
	}
}

char	*line_clean_start_spaces(char *line)
{
	int	i;

	i = 0;
	while (char_is_space(line[i]))
		i++;
	return (&(line[i]));
}

int	char_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == ' ' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}
