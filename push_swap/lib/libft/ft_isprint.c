/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:59:47 by ioriola           #+#    #+#             */
/*   Updated: 2021/05/19 10:46:24 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Tests for any printing character, including space (' ').
*/

int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (1);
	else
		return (0);
}
