/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:18:46 by ioriola           #+#    #+#             */
/*   Updated: 2020/09/15 11:43:42 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			digit_count(long nb, int base)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}

int			digit_u_count(unsigned int nb, int base)
{
	int		i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		i++;
	}
	return (i);
}
