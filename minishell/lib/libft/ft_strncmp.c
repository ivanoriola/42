/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:13:27 by alsanche          #+#    #+#             */
/*   Updated: 2022/07/27 20:44:29 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*c2;
	unsigned char	*c1;

	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	while (*c1 != '\0' && *c2 != '\0')
	{
		if ((*c1 <= 0 || *c1 == 127) || (*c2 <= 0 || *c2 >= 127))
			return ('\0');
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c2;
	unsigned char	*c1;

	i = 0;
	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	while (*c1 != '\0' && *c2 != '\0' && i < n)
	{
		if ((*c1 <= 0 || *c1 == 127) || (*c2 <= 0 || *c2 >= 127))
			return ('\0');
		if (*c1 != *c2)
			return (*c1 - *c2);
		i++;
		c1++;
		c2++;
	}
	if (i != n)
	{
		return (*c1 - *c2);
	}
	return (0);
}
