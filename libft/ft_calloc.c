/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:10:12 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/06 09:40:12 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate memory.
** The allocated memory is aligned such that it can be used for any data type.
** Contiguously allocates enough space for 'count' objects that are 'size'
** bytes of memory each and returns a pointer to the allocated memory.
** The allocated memory is filled with bytes of value zero.
*/

void	*ft_calloc(size_t count, size_t size)
{
	char	*tab;
	size_t	len;

	len = count * size;
	if ((tab = (char *)malloc(len)))
		return (ft_memset(tab, 0, len));
	return (NULL);
}
