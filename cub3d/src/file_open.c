/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 10:37:48 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/16 10:35:24 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	file_open(t_all *all)
{
	int		fd;

	fd = open(all->map.file_name, O_RDONLY);
	if (fd < 0)
		goodbye(all, "Error\nOPENING '.CUB' FILE");
	lines_map_count(fd, all);
	close(fd);
	fd = open(all->map.file_name, O_RDONLY);
	if (fd < 0)
		goodbye(all, "Error\nOPENING '.CUB' FILE");
	lines_get(fd, all);
	close(fd);
	validate(all);
	return (1);
}

void	validate(t_all *all)
{
	if (!all->settings.validate.notexture_ok)
		goodbye(all, "Error\nNORTH TEXTURE MISSING");
	if (!all->settings.validate.sotexture_ok)
		goodbye(all, "Error\nSOUTH TEXTURE MISSING");
	if (!all->settings.validate.eatexture_ok)
		goodbye(all, "Error\nEAST TEXTURE MISSING");
	if (!all->settings.validate.wetexture_ok)
		goodbye(all, "Error\nWEST TEXTURE MISSING");
	if (!all->settings.validate.fcolor_ok)
		goodbye(all, "Error\nFLOOR COLOR MISSING");
	if (!all->settings.validate.ccolor_ok)
		goodbye(all, "Error\nCEILING COLOR MISSING");
	if (!all->settings.validate.map_ok)
		goodbye(all, "Error\nMAP MISSING");
}
