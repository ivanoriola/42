/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivanoriola <ivanoriola@student.42lyon.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 08:21:30 by ioriola           #+#    #+#             */
/*   Updated: 2021/09/22 16:56:45 by ivanoriola       ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	setup(t_all *all)
{
	setup_color_buffer(all);
}

void	update(t_all *all)
{
	if (all->fr.set_type == 'J')
		julia_set(all);
	else if (all->fr.set_type == 'M')
		mandelbrot_set(all);
}

void	render(t_all *all)
{
	render_color_buffer(all);
	draw_image(all);
	screen_info(all);
}
