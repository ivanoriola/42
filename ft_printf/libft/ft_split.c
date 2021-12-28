/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 11:46:49 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/08 09:11:50 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns an array
** of strings obtained by splitting ’s’ using the
** character ’c’ as a delimiter. The array must be
** ended by a NULL pointer.
*/

static int			list_length(char const *s, char c)
{
	int				len;

	len = 0;
	if (*s != c && *s != 0)
	{
		len++;
		s++;
	}
	while (*s != 0)
	{
		if (*s != c && s[-1] == c)
			len++;
		s++;
	}
	return (len + 1);
}

static	char		*ft_strncpy(char *dest, const char *src, size_t len)
{
	char			*final;

	final = dest;
	while (*src != 0 && len > 0)
	{
		*dest++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*dest++ = 0;
		len--;
	}
	return (final);
}

char				**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	char			**list;

	if (s == NULL)
		return (NULL);
	list = (char**)malloc(sizeof(char*) * list_length(s, c));
	if (!list)
		return (NULL);
	j = 0;
	while (*s != 0)
	{
		i = 0;
		while (s[i] != c && s[i] != 0)
			i++;
		if (i)
		{
			list[j++] = ft_strncpy(ft_strnew(i), s, i);
			s = &s[i];
		}
		else
			s++;
	}
	list[j] = NULL;
	return (list);
}
