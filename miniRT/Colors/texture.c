/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:46:49 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:46:50 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	plane_rainbow(t_point inter, t_plane *pl, double dist)
{
	t_color color;

	if (pl->vector.x != 1)
		dist = fabs(fmod((inter.x - pl->center.x) / 50.0, 3));
	else
		dist = fabs(fmod((inter.y - pl->center.y) / 50.0, 3));
	if (dist < 1)
		color = paint(255, ((dist - 0.5) * 2) * 255, (1 - dist * 2) * 255, 1);
	else if (dist >= 1 && dist < 2)
	{
		dist -= 1;
		color = paint((1 - dist * 2) * 255, 255, (dist - 0.5) * 2 * 255, 1);
	}
	else if (dist >= 2 && dist <= 3)
	{
		dist -= 2;
		color = paint((dist - 0.5) * 2 * 255, 255 * (1 - dist * 2), 255, 1);
	}
	color.r < 0 || color.r > 255 ? color.r = 0 : 0;
	color.g < 0 || color.g > 255 ? color.g = 0 : 0;
	color.b < 0 || color.b > 255 ? color.b = 0 : 0;
	return (color);
}

t_color	plane_checkboard(t_point inter, t_plane *pl, double dist)
{
	t_point vector;
	t_color color;

	vector = diff(pl->center, inter);
	if (pl->vector.y != 1)
	{
		vector = apply_rot(vector, pl->vector, create_point(0, 0, 1));
		dist = cos(vector.x / 2) * cos(vector.y / 2);
	}
	else
	{
		vector = apply_rot(vector, pl->vector, create_point(0, 1, 0));
		dist = cos(vector.x / 2) * cos(vector.z / 2);
	}
	if (dist > 0)
		color = pl->color;
	else
		color = paint(0, 0, 0, 1);
	return (color);
}

t_color	sphere_uv(t_point inter, t_sphere *sp, double dist)
{
	double	u;
	double	v;
	t_point	n;

	if (dist == MAX_DISTANCE)
		return (paint(0, 0, 0, 0));
	dist = 0;
	n = normalize_vector(diff(sp->center, inter));
	u = 10 * (0.5 + atan2(n.z, n.x) / (2 * M_PI));
	v = 5 * (0.5 - asin(n.y) / M_PI);
	if ((fmod(u, 1) > 0.5 && fmod(v, 1) > 0.5) ||
		(fmod(u, 1) < 0.5 && fmod(v, 1) < 0.5))
		return (sp->color);
	return (paint(0, 0, 0, 1));
}
