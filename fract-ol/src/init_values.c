/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanoriola <ivanoriola@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:26:54 by ivanoriola        #+#    #+#             */
/*   Updated: 2021/09/22 17:11:51 by ivanoriola       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_values(t_all *all)
{
	all->mlx.mlx_ptr = NULL;
	all->mlx.win_ptr = NULL;
	all->mlx.xres = 1024;
	all->mlx.yres = 768;
	all->mlx.co_buff = NULL;
}

void	reset_values(t_all *all)
{
	all->fr.real = -0.7;
	all->fr.imag = 0.27015;
	all->fr.movey = 0;
	all->fr.max_iter = 300;
	all->fr.zoom = 1;
	if (all->fr.set_type == 'J')
		all->fr.movex = 0;
	else if (all->fr.set_type == 'M')
		all->fr.movex = -0.75;
}
