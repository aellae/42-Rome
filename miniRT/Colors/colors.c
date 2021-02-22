/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:46:09 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:47:19 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	obj_color(t_object *list)
{
	if (list->type == SPHERE)
		return (((t_sphere *)(list->object))->color);
	if (list->type == PLANE)
		return (((t_plane *)(list->object))->color);
	if (list->type == SQUARE)
		return (((t_square *)(list->object))->color);
	if (list->type == TRIANGLE)
		return (((t_triangle *)(list->object))->color);
	if (list->type == CYLINDER)
		return (((t_cylinder *)(list->object))->color);
	if (list->type == CONE)
		return (((t_cone *)(list->object))->color);
	return (paint(0, 0, 0, 0));
}

int		get_pixel_color_bonus(t_get_pixel p)
{
	if (!p.closest)
		p.c.t = 0;
	else if (p.closest->type == R_PLANE)
		p.c = plane_rainbow(p.intersect,
			(t_plane *)p.closest->object, p.distance);
	else if (p.closest->type == C_PLANE)
		p.c = plane_checkboard(p.intersect,
			(t_plane *)p.closest->object, p.distance);
	else if (p.closest->type == C_SPHERE)
		p.c = sphere_uv(p.intersect,
			(t_sphere *)p.closest->object, p.distance);
	else
		p.c = obj_color(p.closest);
	p.c = illuminate(p.c, p.light);
	if (g_filter[0] && g_filter[1] == 0 && p.c.t == 1)
		p.c = apply_filter(p.c);
	return (create_trgb(p.c));
}

int		get_pixel_color(double x, double y)
{
	t_get_pixel p;

	p.closest = 0;
	p.ray.origin = from_image_to_space(x, y);
	p.ray.direction = normalize_vector(diff(g_camera->center, p.ray.origin));
	p.distance = ray_trace(p.ray, &p.closest);
	p.c.t = 1;
	if (p.distance < MAX_DISTANCE)
	{
		p.intersect = move_on_ray(p.ray.origin, p.ray.direction, p.distance);
		p.norm = obj_normal(p.closest, p.ray, p.intersect);
		p.ray.origin = p.intersect;
		p.light = shadow_trace(p.ray, p.norm);
	}
	else
	{
		p.c.t = 0;
		p.light.intensity = 0;
	}
	return (get_pixel_color_bonus(p));
}
