/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:59:30 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/02 09:14:27 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** compares byte string 's1' against byte string 's2'.
** Both strings are assumed to be 'n' bytes long.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *temp_s1;
	unsigned char *temp_s2;

	temp_s1 = (unsigned char*)s1;
	temp_s2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (*temp_s1 == *temp_s2 & n > 0)
	{
		temp_s1++;
		temp_s2++;
		n--;
		if (n == 0)
			return (0);
	}
	if (*temp_s1 != *temp_s2)
	{
		return (*temp_s1 - *temp_s2);
	}
	return (0);
}
