/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:47:43 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:47:45 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	cylinder_norm(t_cylinder *cy, t_point point)
{
	t_point pa;
	t_point pb;

	pa = move_on_ray(cy->center, cy->vector, cy->height / 2);
	pb = move_on_ray(cy->center, cy->vector, -cy->height / 2);
	if (vlen(diff(pa, point)) < (cy->diameter) / 2)
		return (cy->vector);
	if (vlen(diff(pb, point)) < (cy->diameter) / 2)
		return (minus(cy->vector));
	pb = diff(cy->center, point);
	pa = cross_product(pb, cy->vector);
	pa = cross_product(pa, cy->vector);
	return (normalize_vector(pa));
}

t_point	square_norm(t_square *sq, t_ray ray)
{
	t_point norm;

	norm = sq->vector;
	if (dot_product(norm, ray.direction) > 0)
		norm = minus(norm);
	return (norm);
}

t_point	plane_norm(t_plane *pl, t_ray ray)
{
	t_point norm;

	norm = pl->vector;
	if (dot_product(norm, ray.direction) > 0)
		norm = minus(norm);
	return (norm);
}

t_point	triangle_norm(t_triangle *tr, t_ray ray)
{
	t_point norm;
	t_point b;
	t_point c;

	b = diff(tr->point_b, tr->point_a);
	c = diff(tr->point_c, tr->point_a);
	norm = normalize_vector(cross_product(c, b));
	if (dot_product(norm, ray.direction) > 0)
		norm = minus(norm);
	return (norm);
}

t_point	obj_normal(t_object *obj, t_ray ray, t_point intersect)
{
	t_point norm;

	if (obj->type == SQUARE)
		norm = square_norm((t_square *)(obj->object), ray);
	if (obj->type == PLANE || obj->type == C_PLANE || obj->type == R_PLANE)
		norm = plane_norm((t_plane *)(obj->object), ray);
	if (obj->type == TRIANGLE)
		norm = triangle_norm((t_triangle *)(obj->object), ray);
	if (obj->type == SPHERE || obj->type == C_SPHERE)
		norm = normalize_vector(diff((((t_sphere *)(obj->object))->center),
					intersect));
	if (obj->type == CYLINDER)
		norm = cylinder_norm((t_cylinder *)(obj->object), intersect);
	if (obj->type == CONE)
		norm = cone_norm((t_cone *)(obj->object), intersect);
	return (norm);
}
