/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:10:08 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/08 12:20:50 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies 'n' bytes from memory area 'src' to memory area 'dst'.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *temp_src;
	char *temp_dst;

	if (!dst && !src)
		return (0);
	temp_src = (char*)src;
	temp_dst = (char*)dst;
	if (n != 0 || dst != src)
	{
		while (n > 0)
		{
			*temp_dst++ = *temp_src++;
			n--;
		}
	}
	return (dst);
}
