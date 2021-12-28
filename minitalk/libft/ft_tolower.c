/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:05:37 by ioriola           #+#    #+#             */
/*   Updated: 2021/10/14 17:33:42 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Converts a upper-case letter to the corresponding lower-case letter.
*/

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	else
		return (c);
}
