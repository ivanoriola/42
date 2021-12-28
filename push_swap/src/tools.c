/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanoriola <ivanoriola@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 08:57:44 by ioriola           #+#    #+#             */
/*   Updated: 2021/10/04 19:02:27 by ivanoriola       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

short	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == ' ' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

long int	ft_atoli(const char *str)
{
	long int	nbr;
	long int	negative;

	nbr = 0;
	negative = -1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
		if (*str == '-' || *str == '+')
			return (0);
	}
	while (ft_isdigit(*str))
	{
		nbr *= 10;
		nbr -= ((int)*str - '0');
		str++;
	}
	return (negative * nbr);
}

short	has_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	elements_in_str(char *str)
{
	int		count;
	int		i;
	short	element;

	count = 0;
	i = ft_strlen(str) - 1;
	element = 0;
	while (i >= 0)
	{
		while (ft_isspace(str[i]) && i >= 0)
		{
			element = 0;
			i--;
		}
		while (!ft_isspace(str[i]) && i >= 0)
		{
			element = 1;
			i--;
		}
		if (element)
			count++;
	}
	return (count);
}

void	append(char *str, char c)
{
	int		len;

	len = ft_strlen(str);
	str[len] = c;
	str[len + 1] = '\0';
}
