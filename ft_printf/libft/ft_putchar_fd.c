/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 10:45:37 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/09 09:46:13 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the character ’c’ to the given file
** descriptor.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, sizeof(c));
}
