/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 08:14:21 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/17 07:48:40 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	map_check(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->map.height)
	{
		if (!map_row_check((all->map.map[i++])))
			goodbye(all, "Error\nOPEN MAP");
	}
	if (!map_col_check (all, (all->map.map)))
		goodbye(all, "Error\nOPEN MAP");
	return (1);
}

int	map_row_check(char	*str)
{
	int	i;

	i = 0;
	while (char_is_space(str[i]))
		i++;
	if (str[i] != '1')
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' && (str[i - 1] != '1' && str[i - 1] != ' '))
			return (0);
		i++;
	}
	i--;
	while (char_is_space(str[i]))
		i--;
	if (str[i] != '1')
		return (0);
	return (1);
}

int	map_col_check(t_all *all, char **m)
{
	int	r;
	int	c;

	c = 0;
	while (c < all->map.width)
	{
		r = 0;
		while (char_is_space(m[r][c]))
			r++;
		if ((m[r][c]) != '1')
			return (0);
		while (r < all->map.height)
		{
			if ((m[r][c]) == ' ' && m[r - 1][c] != '1' && m[r - 1][c] != ' ')
				return (0);
			r++;
		}
		r--;
		while (char_is_space(m[r][c]))
			r--;
		if ((m[r][c]) != '1')
			return (0);
		c++;
	}
	return (1);
}
