/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 09:43:59 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/08 09:12:43 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function ’f’ to each character of the
** string ’s’ to create a new string (with malloc(3))
** resulting from successive applications of ’f’.
*/

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*out;
	unsigned int	i;

	i = 0;
	if (f && s)
	{
		out = ft_strnew(ft_strlen(s));
		if (!out)
			return (NULL);
		while (s[i] != 0)
		{
			out[i] = (*f)(i, s[i]);
			i++;
		}
		return (out);
	}
	return (NULL);
}
