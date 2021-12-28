/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanoriola <ivanoriola@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 08:54:53 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/22 17:03:31 by ivanoriola       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	setup_color_buffer(t_all *all)
{
	all->mlx.co_buff = (uint32_t *) malloc (sizeof(uint32_t)
			* all->mlx.xres * all->mlx.yres);
	all->mlx.image.img_ptr = mlx_new_image(all->mlx.mlx_ptr,
			all->mlx.xres, all->mlx.yres);
	all->mlx.image.data = (int *)mlx_get_data_addr(
			all->mlx.image.img_ptr, &all->mlx.image.bpp,
			&all->mlx.image.size_l, &all->mlx.image.endian);
}

void	render_color_buffer(t_all *all)
{
	int	x;
	int	y;

	x = 0;
	while (x < all->mlx.xres)
	{
		y = 0;
		while (y < all->mlx.yres)
		{
			all->mlx.image.data[(all->mlx.xres * y) + x]
				= all->mlx.co_buff[(all->mlx.xres * y) + x];
			y++;
		}
		x++;
	}
}

void	draw_image(t_all *all)
{
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr,
		all->mlx.image.img_ptr, 0, 0);
}

void	screen_info(t_all *all)
{
	mlx_string_put(all->mlx.mlx_ptr, all->mlx.win_ptr,
		15, 15, WHITE, "ESC -> Exit");
	mlx_string_put(all->mlx.mlx_ptr, all->mlx.win_ptr,
		15, 30, WHITE, "R -> Reset");
	mlx_string_put(all->mlx.mlx_ptr, all->mlx.win_ptr,
		15, 45, WHITE, "MOUSE WHEEL -> Zoom");
	mlx_string_put(all->mlx.mlx_ptr, all->mlx.win_ptr,
		15, 60, WHITE, "MOUSE L/R BUTTONS -> +/- Iterations");
	mlx_string_put(all->mlx.mlx_ptr, all->mlx.win_ptr,
		15, 75, WHITE, "ARROWS -> Move");
	if (all->fr.set_type == 'J')
	{
		mlx_string_put(all->mlx.mlx_ptr, all->mlx.win_ptr,
			(all->mlx.xres / 2) - 20, 15, WHITE, "JULIA");
		mlx_string_put(all->mlx.mlx_ptr, all->mlx.win_ptr,
			15, 90, WHITE, "W A S D -> Change shape");
	}
	else if (all->fr.set_type == 'M')
		mlx_string_put(all->mlx.mlx_ptr, all->mlx.win_ptr,
			(all->mlx.xres / 2) - 35, 15, WHITE, "MANDELBROT");
}
