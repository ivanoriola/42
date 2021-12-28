/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:15:59 by ioriola           #+#    #+#             */
/*   Updated: 2020/09/10 12:20:08 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_base(int value, int base)
{
	char	*ret;
	char	*tab_base;
	int		size;
	int		i;
	int		sign;

	sign = 0;
	if (value < 0)
	{
		sign = 1;
		value *= -1;
	}
	tab_base = "0123456789ABCDEF";
	size = digit_count(value, base);
	size += (sign ? 1 : 0);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	i = 1;
	sign ? (ret[0] = '-') : 0;
	while (value != 0)
	{
		ret[size - i++] = tab_base[value % base];
		value /= base;
	}
	ret[size] = '\0';
	return (ret);
}

char		*ft_itoa_base_pointer(unsigned long value, int base)
{
	char	*ret;
	char	*tab_base;
	int		size;
	int		i;

	tab_base = "0123456789abcdef";
	size = digit_count(value, base);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	i = 1;
	while (value != 0)
	{
		ret[size - i++] = tab_base[value % base];
		value /= base;
	}
	ret[size] = '\0';
	return (ret);
}

int			istype(char c)
{
	return (ft_strchr("cspdiuxX%", c) ? 1 : 0);
}

int			isflag(char c)
{
	return (ft_strchr("-0.*", c) ? 1 : 0);
}
