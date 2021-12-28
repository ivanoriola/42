/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:25:28 by ioriola           #+#    #+#             */
/*   Updated: 2021/05/19 10:52:17 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Copies bytes from string 'src' to string 'dst'.  If
** the character 'c' (as converted to an unsigned char) occurs in the string
** 'src', the copy stops and a pointer to the byte after the copy of 'c' in the
** string 'dst' is returned.  Otherwise, 'n' bytes are copied, and a NULL
** pointer is returned.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*temp_src;
	unsigned char	*temp_dst;

	temp_src = (unsigned char *)src;
	temp_dst = (unsigned char *)dst;
	while (n > 0)
	{
		*temp_dst = *temp_src;
		if (*temp_src == (unsigned char)c)
			return ((void *)temp_dst + 1);
		temp_dst++;
		temp_src++;
		n--;
	}
	return (NULL);
}
