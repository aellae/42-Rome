/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solid_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:48:05 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:48:06 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect	intercept_sphere(t_sphere *sp, t_ray ray)
{
	t_intersect	ret;
	double		a;
	double		b;
	double		c;
	double		det;

	a = dot_product(ray.direction, ray.direction);
	b = 2 * dot_product(diff(sp->center, ray.origin), ray.direction);
	c = dot_product(diff(sp->center, ray.origin),
					diff(sp->center, ray.origin)) -
		(sp->diameter * sp->diameter) / 4;
	det = b * b - 4 * (a * c);
	if (det < 0)
	{
		ret = no_intersect();
		return (ret);
	}
	ret.distance = (-b - sqrt(det)) / (2 * a);
	if (ret.distance < 0)
		ret = no_intersect();
	return (ret);
}

t_intersect	intercept_cylinder2(t_inter_cyl inter, t_cylinder *cy)
{
	double t;
	double y;

	inter.h = sqrt(inter.h);
	t = (-inter.b - inter.h) / inter.a;
	y = inter.caoc + t * inter.card;
	if (y > 0 && y < inter.caca)
	{
		inter.ret.color = cy->color;
		inter.ret.distance = fabs(t);
		return (inter.ret);
	}
	if (y < 0)
		t = -inter.caoc / inter.card;
	else
		t = (inter.caca - inter.caoc) / inter.card;
	if (fabs(inter.b + inter.a * t) < inter.h)
	{
		inter.ret.color = cy->color;
		inter.ret.distance = fabs(t);
		return (inter.ret);
	}
	inter.ret = no_intersect();
	return (inter.ret);
}

t_intersect	intercept_cylinder(t_cylinder *cy, t_ray ray)
{
	t_inter_cyl inter;

	inter.pa = move_on_ray(cy->center, cy->vector, cy->height / 2);
	inter.pb = move_on_ray(cy->center, cy->vector, -cy->height / 2);
	inter.ca = diff(inter.pa, inter.pb);
	inter.oc = diff(inter.pa, ray.origin);
	inter.caca = dot_product(inter.ca, inter.ca);
	inter.caoc = dot_product(inter.ca, inter.oc);
	inter.card = dot_product(inter.ca, ray.direction);
	inter.a = inter.caca - inter.card * inter.card;
	inter.b = inter.caca * dot_product(inter.oc, ray.direction)
							- inter.caoc * inter.card;
	inter.c = inter.caca * dot_product(inter.oc, inter.oc) -
							inter.caoc * inter.caoc - (cy->diameter / 2) *
							(cy->diameter / 2) * inter.caca;
	inter.h = inter.b * inter.b - inter.a * inter.c;
	if (inter.h < 0)
	{
		inter.ret = no_intersect();
		return (inter.ret);
	}
	inter.ret = intercept_cylinder2(inter, cy);
	return (inter.ret);
}
