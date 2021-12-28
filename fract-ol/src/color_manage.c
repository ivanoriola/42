/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanoriola <ivanoriola@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 10:39:15 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/22 17:08:54 by ivanoriola       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	color_manage(t_all *all, float h_in, float s_in, float v_in)
{
	int	r_out;
	int	g_out;
	int	b_out;

	all->fr.co.h = h_in / 256.0;
	all->fr.co.s = s_in / 256.0;
	all->fr.co.v = v_in / 256.0;
	color_manage_conditional(all);
	r_out = (int)(all->fr.co.r * 255.0);
	g_out = (int)(all->fr.co.g * 255.0);
	b_out = (int)(all->fr.co.b * 255.0);
	all->fr.co.color = r_out * 256 * 256 + g_out * 256 + b_out;
}

void	color_manage_conditional(t_all *all)
{
	int	i;

	if (all->fr.co.s == 0)
	{
		all->fr.co.r = all->fr.co.v;
		all->fr.co.g = all->fr.co.v;
		all->fr.co.b = all->fr.co.v;
	}
	else
	{
		all->fr.co.h *= 6;
		i = (int)(floor(all->fr.co.h));
		all->fr.co.f = all->fr.co.h - i;
		all->fr.co.p = all->fr.co.v * (1 - all->fr.co.s);
		all->fr.co.q = all->fr.co.v * (1 - (all->fr.co.s * all->fr.co.f));
		all->fr.co.t = all->fr.co.v * (1 - (all->fr.co.s * (1 - all->fr.co.f)));
		color_switch1(all, i);
	}
}

void	color_switch1(t_all *all, int i)
{
	if (i == 0)
	{
		all->fr.co.r = all->fr.co.v;
		all->fr.co.g = all->fr.co.t;
		all->fr.co.b = all->fr.co.p;
	}
	else if (i == 1)
	{
		all->fr.co.r = all->fr.co.q;
		all->fr.co.g = all->fr.co.v;
		all->fr.co.b = all->fr.co.p;
	}
	else if (i == 2)
	{
		all->fr.co.r = all->fr.co.p;
		all->fr.co.g = all->fr.co.v;
		all->fr.co.b = all->fr.co.t;
	}
	else
		color_switch2(all, i);
}

void	color_switch2(t_all *all, int i)
{
	if (i == 3)
	{
		all->fr.co.r = all->fr.co.p;
		all->fr.co.g = all->fr.co.q;
		all->fr.co.b = all->fr.co.v;
	}
	else if (i == 4)
	{
		all->fr.co.r = all->fr.co.t;
		all->fr.co.g = all->fr.co.p;
		all->fr.co.b = all->fr.co.v;
	}
	else if (i == 5)
	{
		all->fr.co.r = all->fr.co.v;
		all->fr.co.g = all->fr.co.p;
		all->fr.co.b = all->fr.co.q;
	}
}
