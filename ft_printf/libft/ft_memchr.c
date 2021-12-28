/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:48:38 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/02 09:14:27 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of 'c' (converted to an
** unsigned char) in string 's'.
*/

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	while (n > 0)
	{
		str = (unsigned char*)s;
		if (*str == (unsigned char)c)
		{
			return (str);
		}
		s++;
		n--;
	}
	return (NULL);
}
