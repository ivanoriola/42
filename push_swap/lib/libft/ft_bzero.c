/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 12:01:40 by ioriola           #+#    #+#             */
/*   Updated: 2021/05/19 10:38:09 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Writes 'n' zeroed bytes to the string 's'.
** If 'n' is zero, does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	char	*temp;

	temp = s;
	while (n != 0)
	{
		*temp++ = 0;
		n--;
	}
}
