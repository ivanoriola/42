/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 08:23:11 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/08 12:27:29 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies up to 'dstsize' - 1 characters from the string 'src' to 'dst',
** NUL-terminating the result if 'dstsize' is not 0.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	size;

	count = 0;
	size = 0;
	if (!dst || !src)
		return (0);
	while (src[size])
		size++;
	if (!dstsize)
		return (size);
	while (src[count] && count < dstsize - 1)
	{
		dst[count] = src[count];
		count++;
	}
	dst[count] = '\0';
	return (size);
}
