/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 11:22:32 by ioriola           #+#    #+#             */
/*   Updated: 2020/07/08 09:15:04 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Tests for any character for which isupper() or islower() is true.
*/

static	int	ft_isupper(int c)
{
	return ((c >= 'A' && c <= 'Z') ? 1 : 0);
}

static	int	ft_islower(int c)
{
	return ((c >= 'a' && c <= 'z') ? 1 : 0);
}

int			ft_isalpha(int c)
{
	return ((ft_isupper(c) || ft_islower(c)) ? 1 : 0);
}
