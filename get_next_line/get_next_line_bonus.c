/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 08:31:14 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/29 09:40:53 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*
** Returns a line read from a
** file descriptor, without the newline.
** 1 :  A line has been read
** 0 :  EOF has been reached
** -1 :  An error happened
*/

int			new_line(char **s, char **line)
{
	int		len;
	char	*aux;

	len = 0;
	while (((*s)[len] != '\n' && (*s)[len] != '\0'))
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		aux = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = aux;
	}
	else
	{
		*line = ft_strdup(*s);
		free(*s);
		*s = NULL;
		return (0);
	}
	return (1);
}

int			return_value(int fd, int n_bytes, char **s, char **line)
{
	if (n_bytes < 0)
		return (-1);
	else if (n_bytes == 0 && s[fd] == '\0')
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (new_line(&s[fd], line));
}

int			get_next_line(int fd, char **line)
{
	char			*buff;
	int				n_bytes;
	static char		*fd_string[1024];
	char			*aux;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	while ((n_bytes = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[n_bytes] = '\0';
		if (fd_string[fd] == NULL)
			fd_string[fd] = ft_strdup(buff);
		else
		{
			aux = ft_strjoin(fd_string[fd], buff);
			free(fd_string[fd]);
			fd_string[fd] = aux;
		}
		if (ft_strchr(fd_string[fd], '\n'))
			break ;
	}
	free(buff);
	return (return_value(fd, n_bytes, fd_string, line));
}
