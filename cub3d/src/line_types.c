/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 08:03:17 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/15 09:30:31 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	line_is_texture(char *line)
{
	line = line_clean_start_spaces(line);
	if (line[0] == '\0')
		return (0);
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		return (1);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		return (2);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		return (3);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		return (4);
	else
		return (0);
}

int	line_is_color(char *line)
{
	line = line_clean_start_spaces(line);
	if (line[0] == '\0')
		return (0);
	if (line[0] == 'F' && line[1] == ' ')
		return (1);
	else if (line[0] == 'C' && line[1] == ' ')
		return (2);
	else
		return (0);
}

int	line_is_map(char *line)
{
	int	i;
	int	spaces;

	i = 0;
	spaces = 0;
	if (line[0] == '\0')
		return (0);
	while (line[i])
	{
		if (!char_is_map(line[i]))
			return (0);
		if (char_is_space(line[i]))
			spaces++;
		i++;
	}
	if (spaces == ((int) ft_strlen(line)))
		return (0);
	return (1);
}

int	char_is_map(char c)
{
	if (c == '0' || c == '1'
		|| c == 'N' || c == 'S' || c == ' '
		|| c == 'W' || c == 'E' || c == '\t')
		return (1);
	else
		return (0);
}
