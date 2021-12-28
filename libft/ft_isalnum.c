/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:52:59 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/06 12:54:41 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Tests for any character for which isalpha() or isdigit() is true.
*/

int		ft_isalnum(int c)
{
	return ((ft_isalpha(c) || ft_isdigit(c)) ? 1 : 0);
}
