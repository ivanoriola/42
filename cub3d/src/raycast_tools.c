/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioriola <ioriola@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 09:03:06 by ioriola           #+#    #+#             */
/*   Updated: 2021/07/28 08:03:04 by ioriola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	normalize_angle(float angle)
{
	angle = remainderf(angle, TWO_PI);
	if (angle < 0)
		angle += TWO_PI;
	return (angle);
}

float	get_distance(float x1, float y1, float x2, float y2)
{
	return ((float) sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
