/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 08:58:03 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/09 11:26:39 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a "fresh" string end-
** ing with '\0'. Each character of the string is initialized at
** '\0'. If the allocation fails the function returns NULL.
*/

static	void	*memoryalloc(size_t size)
{
	void		*dest;
	char		*clean;

	dest = malloc(size);
	clean = dest;
	if (dest)
	{
		while (size != 0)
		{
			*clean++ = 0;
			size--;
		}
		return (dest);
	}
	else
	{
		return (NULL);
	}
}

char			*ft_strnew(size_t size)
{
	return (memoryalloc(size + 1));
}
