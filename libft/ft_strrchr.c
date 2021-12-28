/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 09:41:45 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/08 12:23:13 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the last occurrence of 'c' (converted to a
** char) in the string pointed to by 's'.  The terminating null character is
** considered to be part of the string; therefore if 'c' is `\0', the func-
** tions locate the terminating `\0'.
*/

char		*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i--;
	}
	return (NULL);
}
