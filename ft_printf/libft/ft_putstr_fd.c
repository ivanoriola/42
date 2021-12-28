/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:51:15 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/08 09:13:38 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string ’s’ to the given file
** descriptor.
*/

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (!(s[i] == '\0'))
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
