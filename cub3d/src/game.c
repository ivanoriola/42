/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:10:50 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/16 07:55:42 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	setup(t_all *all)
{
	get_player_initial_pos_and_dir(all);
	load_textures(all);
	setup_color_buffer(all);
}

void	render(t_all *all)
{
	generate_3d_projection(all);
	render_color_buffer(all);
	draw_frame_image(all);
	draw_minimap(all->map.map, all);
	draw_player(all);
}

void	update(t_all *all)
{
	cast_all_rays(all);
}
