/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 10:20:42 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/06 10:34:20 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the first occurrence of the null-termi-nated string
** 'needle' in the string 'haystack', where not more than 'len' char-
** acters are searched.  Characters that appear after a `\0'
** character are not searched.
*/

char			*ft_strnstr(const char *stack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)stack);
	while (stack[i] && i < len)
	{
		while (stack[i + j] == needle[j] && needle[j] && i + j < len)
			j++;
		if (needle[j] == '\0')
			return ((char *)(stack + i));
		i++;
		j = 0;
	}
	return (0);
}
