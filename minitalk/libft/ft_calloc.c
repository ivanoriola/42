/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:10:12 by ioriola           #+#    #+#             */
/*   Updated: 2021/05/19 11:01:00 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
	tab = (char *)malloc(len);
	if ((tab))
		return (ft_memset(tab, 0, len));
	return (NULL);
}
