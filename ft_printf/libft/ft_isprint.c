/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:59:47 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/02 12:05:09 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Tests for any printing character, including space (` ').
*/

int	ft_isprint(int c)
{
	return ((c < 32 || c > 126) ? 0 : 1);
}
