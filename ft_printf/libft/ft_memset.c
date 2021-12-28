/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 11:39:18 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/08 10:42:04 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes 'len' bytes of value 'c' (converted to an
** unsigned char) to the string 'b'.
*/

void		*ft_memset(void *b, int c, size_t len)
{
	char	*a;

	a = (char *)b;
	while (len > 0)
	{
		*a++ = (unsigned char)c;
		len--;
	}
	return (b);
}
