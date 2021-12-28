/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:30:05 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/15 11:01:20 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	cast_all_rays(t_all *all)
{
	t_ray	*ray;
	int		i;
	float	angle;
	float	player_dir_rad;

	player_dir_rad = all->player.dir * (PI / 180);
	angle = player_dir_rad - (all->rayc.fov_angle / 2);
	all->player.rel_x = all->player.x + (all->map.til_siz / 2.0f);
	all->player.rel_y = all->player.y + (all->map.til_siz / 2.0f);
	i = 0;
	while (i < all->rayc.num_of_rays)
	{
		ray = &(all->rayc.rays[i]);
		init_ray_values(ray);
		ray->angle = angle;
		cast_ray(all, ray);
		angle += all->rayc.fov_angle / all->rayc.num_of_rays;
		i++;
	}
}

void	cast_ray(t_all *all, t_ray	*ray)
{
	ray->angle = normalize_angle(ray->angle);
	ray->down = (ray->angle > 0) && (ray->angle < PI);
	ray->up = !ray->down;
	ray->right = (ray->angle > THREEHALF_PI) || (ray->angle < HALF_PI);
	ray->left = !ray->right;
	cast_ray_horizontal(all, ray);
	cast_ray_vertical(all, ray);
	calculate_hit_distance(all, ray);
	select_minimal_hit_distance(ray);
	wall_facing(ray);
}

void	calculate_hit_distance(t_all *all, t_ray *ray)
{
	if (ray->hor_w_hit)
	{
		ray->hor_hit_dist
			= get_distance(all->player.rel_x, all->player.rel_y,
				ray->hor_w_hit_x, ray->hor_w_hit_y);
	}
	else
		ray->hor_hit_dist = FLT_MAX;
	if (ray->ver_w_hit)
	{
		ray->ver_hit_dist
			= get_distance(all->player.rel_x, all->player.rel_y,
				ray->ver_w_hit_x, ray->ver_w_hit_y);
	}
	else
		ray->ver_hit_dist = FLT_MAX;
}

void	select_minimal_hit_distance(t_ray *ray)
{
	if (ray->ver_hit_dist < ray->hor_hit_dist)
	{
		ray->distance = ray->ver_hit_dist;
		ray->wall_hit_x = ray->ver_w_hit_x;
		ray->wall_hit_y = ray->ver_w_hit_y;
		ray->wall_content = ray->ver_w_cont;
		ray->hit_ver = 1;
	}
	else
	{
		ray->distance = ray->hor_hit_dist;
		ray->wall_hit_x = ray->hor_w_hit_x;
		ray->wall_hit_y = ray->hor_w_hit_y;
		ray->wall_content = ray->hor_w_cont;
		ray->hit_ver = 0;
	}
}
