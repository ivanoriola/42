/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:26:54 by ivanoriola        #+#    #+#             */
/*   Updated: 2021/09/16 10:31:43 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	init_values(t_all *all)
{
	all->settings.xres = 1280;
	all->settings.yres = 720;
	all->settings.validate.notexture_ok = 0;
	all->settings.validate.sotexture_ok = 0;
	all->settings.validate.eatexture_ok = 0;
	all->settings.validate.wetexture_ok = 0;
	all->settings.validate.fcolor_ok = 0;
	all->settings.validate.ccolor_ok = 0;
	all->settings.validate.map_ok = 0;
	all->map.til_map = 4;
	all->map.til_siz = 1;
	all->map.mrg = 10;
}

void	init_rayc_values(t_all *all)
{
	all->rayc.fov_angle = 60 * (PI / 180);
	all->rayc.num_of_rays = all->settings.xres;
	all->rayc.rays = (t_ray *) malloc (sizeof(t_ray) * all->rayc.num_of_rays);
}

void	init_ray_values(t_ray *ray)
{
	ray->angle = 0;
	ray->wall_hit_x = 0;
	ray->wall_hit_y = 0;
	ray->distance = 0;
	ray->hit_ver = 0;
	ray->up = 0;
	ray->down = 0;
	ray->left = 0;
	ray->right = 0;
	ray->wall_content = -1;
	ray->wall_facing = -1;
	ray->xintercept = 0;
	ray->yintercept = 0;
	ray->xstep = 0;
	ray->ystep = 0;
	ray->x_to_check = 0;
	ray->y_to_check = 0;
	init_ray_values2(ray);
}

void	init_ray_values2(t_ray *ray)
{
	ray->hor_w_hit = 0;
	ray->hor_w_hit_x = 0;
	ray->hor_w_hit_y = 0;
	ray->hor_w_cont = -1;
	ray->ver_touch_x = 0;
	ray->ver_touch_y = 0;
	ray->ver_w_hit = 0;
	ray->ver_w_hit_x = 0;
	ray->ver_w_hit_y = 0;
	ray->ver_w_cont = -1;
	ray->hor_touch_x = 0;
	ray->hor_touch_y = 0;
	ray->hor_hit_dist = 0;
	ray->ver_hit_dist = 0;
}
