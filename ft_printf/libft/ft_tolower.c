/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:05:37 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/06 10:34:48 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts a upper-case letter to the corresponding lower-case letter.
*/

int	ft_tolower(int c)
{
	return ((c > 64 && c < 91) ? c + 32 : c);
}
