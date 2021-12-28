/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:38:13 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/08 12:21:59 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies 'len' bytes from string 'src' to string 'dst'.
** The two strings may overlap; the copy is always done in a non-destructive
** manner.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*temp_dst;
	const unsigned char	*temp_src;

	if (!dst && !src)
		return (0);
	temp_dst = (unsigned char*)dst;
	temp_src = (unsigned char*)src;
	i = 0;
	if (temp_src < temp_dst)
	{
		while (++i <= len)
		{
			temp_dst[len - i] = temp_src[len - i];
		}
	}
	else
	{
		while (len-- > 0)
		{
			*(temp_dst++) = *(temp_src++);
		}
	}
	return (dst);
}
