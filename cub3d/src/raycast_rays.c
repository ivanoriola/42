/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 10:11:35 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/14 09:19:45 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	cast_ray_horizontal(t_all *all, t_ray *ray)
{
	ray->yintercept
		= floor(all->player.rel_y / all->map.til_siz) * all->map.til_siz;
	if (ray->down)
		ray->yintercept += all->map.til_siz;
	ray->xintercept = all->player.rel_x
		+ (ray->yintercept - all->player.rel_y) / tan(ray->angle);
	ray->ystep = all->map.til_siz;
	if (ray->up)
		ray->ystep *= -1;
	ray->xstep = all->map.til_siz / tan(ray->angle);
	if ((ray->left && ray->xstep > 0) || (ray->right && ray->xstep < 0))
		ray->xstep *= -1;
	ray->hor_touch_x = ray->xintercept;
	ray->hor_touch_y = ray->yintercept;
	cast_ray_horizontal2(all, ray);
}

void	cast_ray_horizontal2(t_all *all, t_ray *ray)
{
	while (ray->hor_touch_x >= 0 && ray->hor_touch_x <= all->map.width
		&& ray->hor_touch_y >= 0 && ray->hor_touch_y <= all->map.height)
	{
		ray->x_to_check = ray->hor_touch_x;
		ray->y_to_check = ray->hor_touch_y;
		if (ray->up)
			ray->y_to_check -= 1;
		if (map_xy_content(all, ray->x_to_check, ray->y_to_check) != '0')
		{
			ray->hor_w_hit_x = ray->hor_touch_x;
			ray->hor_w_hit_y = ray->hor_touch_y;
			ray->hor_w_cont
				= map_xy_content(all,
					(int) floor(ray->x_to_check / all->map.til_siz),
					(int) floor(ray->y_to_check / all->map.til_siz));
			ray->hor_w_hit = 1;
			break ;
		}
		else
		{
			ray->hor_touch_x += ray->xstep;
			ray->hor_touch_y += ray->ystep;
		}
	}
}

void	cast_ray_vertical(t_all *all, t_ray *ray)
{
	ray->xintercept
		= floor(all->player.rel_x / all->map.til_siz) * all->map.til_siz;
	if (ray->right)
		ray->xintercept += all->map.til_siz;
	ray->yintercept = all->player.rel_y
		+ (ray->xintercept - all->player.rel_x) * tan(ray->angle);
	ray->xstep = all->map.til_siz;
	if (ray->left)
		ray->xstep *= -1;
	ray->ystep = all->map.til_siz * tan(ray->angle);
	if ((ray->up && ray->ystep > 0) || (ray->down && ray->ystep < 0))
		ray->ystep *= -1;
	ray->ver_touch_x = ray->xintercept;
	ray->ver_touch_y = ray->yintercept;
	cast_ray_vertical2(all, ray);
}

void	cast_ray_vertical2(t_all *all, t_ray *ray)
{
	while (ray->ver_touch_x >= 0 && ray->ver_touch_x <= all->map.width
		&& ray->ver_touch_y >= 0 && ray->ver_touch_y <= all->map.height)
	{
		ray->x_to_check = ray->ver_touch_x;
		ray->y_to_check = ray->ver_touch_y;
		if (ray->left)
			ray->x_to_check -= 1;
		if (map_xy_content(all, ray->x_to_check, ray->y_to_check) != '0')
		{
			ray->ver_w_hit_x = ray->ver_touch_x;
			ray->ver_w_hit_y = ray->ver_touch_y;
			ray->ver_w_cont
				= map_xy_content(all,
					(int) floor(ray->x_to_check / all->map.til_siz),
					(int) floor(ray->y_to_check / all->map.til_siz));
			ray->ver_w_hit = 1;
			break ;
		}
		else
		{
			ray->ver_touch_x += ray->xstep;
			ray->ver_touch_y += ray->ystep;
		}
	}
}

void	wall_facing(t_ray *ray)
{
	if (!ray->hit_ver)
	{
		if (ray->up)
			ray->wall_facing = 1;
		else
			ray->wall_facing = 0;
	}
	else
	{
		if (ray->left)
			ray->wall_facing = 2;
		else
			ray->wall_facing = 3;
	}
}
