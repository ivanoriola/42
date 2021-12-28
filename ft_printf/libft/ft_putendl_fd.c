/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:07:11 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/08 09:14:18 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string ’s’ to the given file
** descriptor, followed by a newline.
*/

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (!(s[i] == '\0'))
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}
