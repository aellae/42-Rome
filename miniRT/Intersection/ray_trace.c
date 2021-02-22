/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:47:53 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:47:55 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect	find_intersect(t_object *list, t_ray ray)
{
	t_intersect curr_intersect;

	if (list->type == SPHERE || list->type == C_SPHERE ||
		list->type == R_SPHERE)
		curr_intersect = intercept_sphere((t_sphere *)list->object, ray);
	if (list->type == PLANE || list->type == C_PLANE || list->type == R_PLANE)
		curr_intersect = intercept_plane((t_plane *)list->object, ray);
	if (list->type == SQUARE)
		curr_intersect = intercept_square((t_square *)list->object, ray);
	if (list->type == TRIANGLE)
		curr_intersect = intercept_triangle((t_triangle *)list->object, ray);
	if (list->type == CYLINDER)
		curr_intersect = intercept_cylinder((t_cylinder *)list->object, ray);
	if (list->type == CONE)
		curr_intersect = intercept_cone((t_cone *)list->object, ray);
	return (curr_intersect);
}

double		reflect(t_ray ray, double min_distance, t_object **sp)
{
	t_point		norm;

	ray.origin = move_on_ray(ray.origin, ray.direction, min_distance);
	norm = normalize_vector(diff((((t_sphere *)((*sp)->object))->center),
		ray.origin));
	min_distance = -dot_product(ray.direction, norm);
	ray.direction = diff(ray.direction, multiply_vec(norm, 2 * min_distance));
	ray.direction = normalize_vector(ray.direction);
	ray.origin = move_on_ray(ray.origin, ray.direction, 0.1);
	return (ray_trace(ray, sp));
}

double		ray_trace(t_ray ray, t_object **closest_obj)
{
	double		min_distance;
	t_intersect	curr_intersect;
	t_object	*list;

	list = g_objects;
	min_distance = MAX_DISTANCE + 1;
	while (list)
	{
		curr_intersect = find_intersect(list, ray);
		if (min_distance > curr_intersect.distance)
		{
			min_distance = curr_intersect.distance;
			*closest_obj = list;
		}
		list = list->next;
	}
	if ((*closest_obj)->type == R_SPHERE)
		return (reflect(ray, min_distance, closest_obj));
	if (min_distance >= MAX_DISTANCE)
		*closest_obj = 0;
	return (min_distance);
}

t_point		from_image_to_space(double x, double y)
{
	t_point	ret;
	double	ratio;
	double	a;

	ratio = (double)g_xres / (double)g_yres;
	ret.x = ((double)x / (double)g_xres - 0.5) * ratio;
	ret.y = (((double)y / (double)g_yres - 0.5)) * -1;
	a = ratio / sin((double)g_camera->fov / 2);
	ret.z = a * cos((double)g_camera->fov / 2);
	ret.z = 1;
	ret = apply_rot(ret, create_point(0, 0, 1), g_camera->direction);
	ret = add(ret, g_camera->center);
	return (ret);
}
