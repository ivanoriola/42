/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanoriola <ivanoriola@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 09:45:45 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/22 17:16:44 by ivanoriola       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	julia_set(t_all *all)
{
	int	y;
	int	x;

	y = 0;
	while (y < all->mlx.yres)
	{
		x = 0;
		while (x < all->mlx.xres)
		{
			all->fr.new_real = 1.5 * (x - all->mlx.xres / 2)
				/ (0.5 * all->fr.zoom * all->mlx.xres) + all->fr.movex;
			all->fr.new_imag = (y - all->mlx.yres / 2)
				/ (0.5 * all->fr.zoom * all->mlx.yres) + all->fr.movey;
			iteration(x, y, all);
			x++;
		}
		y++;
	}
}

void	mandelbrot_set(t_all *all)
{
	int	y;
	int	x;

	y = 0;
	while (y < all->mlx.yres)
	{
		x = 0;
		while (x < all->mlx.xres)
		{
			all->fr.real = 1.5 * (x - all->mlx.xres / 2)
				/ (0.5 * all->fr.zoom * all->mlx.xres) + all->fr.movex;
			all->fr.imag = (y - all->mlx.yres / 2)
				/ (0.5 * all->fr.zoom * all->mlx.yres) + all->fr.movey;
			all->fr.new_real = 0;
			all->fr.new_imag = 0;
			all->fr.old_real = 0;
			all->fr.old_imag = 0;
			iteration(x, y, all);
			x++;
		}
		y++;
	}
}

void	iteration(int x, int y, t_all *all)
{
	int	i;

	i = 0;
	while (i < all->fr.max_iter)
	{
		all->fr.old_real = all->fr.new_real;
		all->fr.old_imag = all->fr.new_imag;
		all->fr.new_real = all->fr.old_real * all->fr.old_real
			- all->fr.old_imag * all->fr.old_imag + all->fr.real;
		all->fr.new_imag = 2 * all->fr.old_real
			* all->fr.old_imag + all->fr.imag;
		if ((all->fr.new_real * all->fr.new_real
				+ all->fr.new_imag * all->fr.new_imag) > 4)
			break ;
		i++;
	}
	color_manage(all, i % 256, 255, 255 * (i < all->fr.max_iter));
	all->mlx.co_buff[(all->mlx.xres * y) + x] = all->fr.co.color;
}
