/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_3d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 10:54:52 by ioriola           #+#    #+#             */
/*   Updated: 2021/08/31 10:45:49 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	load_textures(t_all *all)
{
	all->render.walls[0].img_ptr
		= mlx_xpm_file_to_image(all->mlx.mlx_ptr, all->settings.notexture,
			&all->render.walls[0].width, &all->render.walls[0].height);
	all->render.walls[0].data = (int *)mlx_get_data_addr(
			all->render.walls[0].img_ptr, &all->render.walls[0].bpp,
			&all->render.walls[0].size_l, &all->render.walls[0].endian);
	all->render.walls[1].img_ptr
		= mlx_xpm_file_to_image(all->mlx.mlx_ptr, all->settings.sotexture,
			&all->render.walls[1].width, &all->render.walls[1].height);
	all->render.walls[1].data = (int *)mlx_get_data_addr(
			all->render.walls[1].img_ptr, &all->render.walls[1].bpp,
			&all->render.walls[1].size_l, &all->render.walls[1].endian);
	all->render.walls[2].img_ptr
		= mlx_xpm_file_to_image(all->mlx.mlx_ptr, all->settings.eatexture,
			&all->render.walls[2].width, &all->render.walls[2].height);
	all->render.walls[2].data = (int *)mlx_get_data_addr(
			all->render.walls[2].img_ptr, &all->render.walls[2].bpp,
			&all->render.walls[2].size_l, &all->render.walls[2].endian);
	all->render.walls[3].img_ptr
		= mlx_xpm_file_to_image(all->mlx.mlx_ptr, all->settings.wetexture,
			&all->render.walls[3].width, &all->render.walls[3].height);
	all->render.walls[3].data = (int *)mlx_get_data_addr(
			all->render.walls[3].img_ptr, &all->render.walls[3].bpp,
			&all->render.walls[3].size_l, &all->render.walls[3].endian);
}

void	generate_3d_projection(t_all *all)
{
	int	i;

	i = 0;
	all->render.dist_proj_plane = (all->settings.xres / 2)
		/ tan(all->rayc.fov_angle / 2);
	while (i < all->rayc.num_of_rays)
	{
		all->render.projwall_height = (all->map.til_siz
				/ all->rayc.rays[i].distance)
			* all->render.dist_proj_plane;
		all->render.wall_strip_height
			= (int) all->render.projwall_height;
		all->render.wall_top_pixel = (all->settings.yres / 2)
			- (all->render.wall_strip_height / 2);
		if (all->render.wall_top_pixel < 0)
			all->render.wall_top_pixel = 0;
		all->render.wall_bottom_pixel = (all->settings.yres / 2)
			+ (all->render.wall_strip_height / 2);
		if (all->render.wall_top_pixel > all->settings.yres)
			all->render.wall_top_pixel = all->settings.yres;
		render_ceiling_floor(i, all);
		render_wall(i, all);
		i++;
	}
}

void	render_ceiling_floor(int i, t_all *all)
{
	int	y;

	y = 0;
	while (y < all->render.wall_top_pixel)
	{
		all->render.color_buffer[(all->settings.xres * y) + i]
			= all->settings.ccolor;
		y++;
	}
	y = all->render.wall_bottom_pixel;
	while (y < all->settings.yres)
	{
		all->render.color_buffer[(all->settings.xres * y) + i]
			= all->settings.fcolor;
		y++;
	}
}

void	render_wall(int i, t_all *all)
{
	int	orientation;

	orientation = all->rayc.rays[i].wall_facing;
	if (all->rayc.rays[i].hit_ver)
	{
		all->render.offset_x
			= (int)(all->render.walls[orientation].height
				* all->rayc.rays[i].wall_hit_y)
			% (all->render.walls[orientation].height * all->map.til_siz);
	}
	else
	{
		all->render.offset_x
			= (int)(all->render.walls[orientation].width
				* all->rayc.rays[i].wall_hit_x)
			% (all->render.walls[orientation].width * all->map.til_siz);
	}
	render_wall2(i, all);
}

void	render_wall2(int i, t_all *all)
{
	int	y;
	int	orientation;

	orientation = all->rayc.rays[i].wall_facing;
	y = all->render.wall_top_pixel;
	while (y < all->render.wall_bottom_pixel)
	{
		all->render.dist_top = y + (all->render.wall_strip_height / 2)
			- (all->settings.yres / 2);
		all->render.offset_y = all->render.dist_top
			* ((float) all->render.walls[orientation].height
				/ all->render.wall_strip_height);
		all->render.pix_color
			= all->render.walls[orientation].data[
			(all->render.walls[orientation].width * all->render.offset_y)
			+ all->render.offset_x];
		all->render.color_buffer[(all->settings.xres * y) + i]
			= all->render.pix_color;
		y++;
	}
}
