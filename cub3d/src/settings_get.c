/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:44:11 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/16 10:22:21 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	int_len(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		len = 1;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

void	get_textures(t_all *all, char *line, int texture)
{
	char	*file;
	int		i;
	int		j;

	line = line_clean_start_spaces(line);
	i = 2;
	while (line[i] != '\0')
		i++;
	file = malloc(sizeof(char) * (i - 1));
	if (!(file))
		return ;
	i = 2;
	j = 0;
	while (line[i] != '\0')
		file[j++] = line[(i)++];
	file[j] = '\0';
	if (access(line_clean_start_spaces(file), F_OK) != -1)
		set_textures(all, line_clean_start_spaces(file), texture);
	else
		goodbye(all, "Error\nTEXTURE FILE NOT FOUND");
	free (file);
}

void	set_textures(t_all *all, char *file, int texture)
{
	file = line_clean_start_spaces(file);
	if (texture == 1)
	{
		all->settings.notexture = ft_strdup(file);
		all->settings.validate.notexture_ok = 1;
	}
	else if (texture == 2)
	{
		all->settings.sotexture = ft_strdup(file);
		all->settings.validate.sotexture_ok = 1;
	}
	else if (texture == 3)
	{
		all->settings.wetexture = ft_strdup(file);
		all->settings.validate.wetexture_ok = 1;
	}
	else if (texture == 4)
	{
		all->settings.eatexture = ft_strdup(file);
		all->settings.validate.eatexture_ok = 1;
	}
}

void	get_color(t_all *all, char *line, int color)
{
	int	r;
	int	g;
	int	b;

	line = line_clean_start_spaces(line);
	line += 1;
	r = ft_atoi(line);
	line = line_clean_start_spaces(line);
	line += int_len(r) + 1;
	g = ft_atoi(line);
	line = line_clean_start_spaces(line);
	line += int_len(g) + 1;
	b = ft_atoi(line);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		goodbye(all, "Error\nNOT A VALID COLOR");
	if (color == 1)
	{
		all->settings.fcolor = r * 256 * 256 + g * 256 + b;
		all->settings.validate.fcolor_ok = 1;
	}
	else if (color == 2)
	{
		all->settings.ccolor = r * 256 * 256 + g * 256 + b;
		all->settings.validate.ccolor_ok = 1;
	}
}
