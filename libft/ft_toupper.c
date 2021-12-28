/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:02:49 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/02 12:05:09 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Converts a lower-case letter to the corresponding upper-case letter.
*/

int	ft_toupper(int c)
{
	return ((c > 96 && c < 123) ? c - 32 : c);
}
