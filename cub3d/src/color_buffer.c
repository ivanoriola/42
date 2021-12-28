/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 08:01:25 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/16 10:44:37 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	setup_color_buffer(t_all *all)
{
	all->render.color_buffer = (uint32_t *) malloc (sizeof(uint32_t)
			* all->settings.xres * all->settings.yres);
	all->render.image.img_ptr = mlx_new_image(all->mlx.mlx_ptr,
			all->settings.xres, all->settings.yres);
	all->render.image.data = (int *)mlx_get_data_addr(
			all->render.image.img_ptr, &all->render.image.bpp,
			&all->render.image.size_l, &all->render.image.endian);
}

void	render_color_buffer(t_all *all)
{
	int	x;
	int	y;

	x = 0;
	while (x < all->settings.xres)
	{
		y = 0;
		while (y < all->settings.yres)
		{
			all->render.image.data[(all->settings.xres * y) + x]
				= all->render.color_buffer[(all->settings.xres * y) + x];
			y++;
		}
		x++;
	}
}

void	draw_frame_image(t_all *all)
{
	mlx_put_image_to_window(all->mlx.mlx_ptr, all->mlx.win_ptr,
		all->render.image.img_ptr, 0, 0);
}
