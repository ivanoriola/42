/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 08:31:48 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/02 12:57:28 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends string 'src' to the end of 'dst'.  It will append at most
** 'dstsize' - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
** 'dstsize' is 0 or the original 'dst' string was longer than 'dstsize'
** (in practice this should not happen as it means that either 'dstsize'
** is incorrect or that 'dst' is not a proper string).
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	dest_size;
	size_t	src_size;

	count = 0;
	dest_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dest_size >= dstsize)
		return (src_size + dstsize);
	while (src[count] && (dstsize - 1 > count + dest_size))
	{
		dst[count + dest_size] = src[count];
		count++;
	}
	dst[count + dest_size] = '\0';
	return (dest_size + src_size);
}
