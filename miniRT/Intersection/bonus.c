/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:47:37 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:48:25 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point		cone_norm(t_cone *co, t_point point)
{
	t_point pa;
	t_point pb;

	pb = diff(co->center, point);
	pa = cross_product(pb, co->vector);
	pa = cross_product(pa, co->vector);
	return (normalize_vector(pa));
}

t_intersect	intercept_cone2(t_inter_co co, t_cone *cone, t_ray ray)
{
	double		t1;
	double		t2;
	t_intersect ret;
	t_point		temp;

	if (co.det < 0.0)
		return (no_intersect());
	co.det = sqrt(co.det);
	t1 = (-co.b - co.det) / (2 * co.a);
	t2 = (-co.b + co.det) / (2 * co.a);
	if (t1 < 0.0 || (t2 > 0.0 && t2 < t1))
		t1 = t2;
	if (t1 < 0.0)
		return (no_intersect());
	temp = move_on_ray(ray.origin, ray.direction, t1);
	if (temp.y > cone->center.y || temp.y < cone->center.y - cone->height)
		return (no_intersect());
	ret.distance = t1;
	ret.color = cone->color;
	return (ret);
}

t_intersect	intercept_cone(t_cone *cone, t_ray ray)
{
	t_inter_co	co;

	co.w = diff(cone->center, ray.origin);
	co.vv = dot_product(ray.direction, ray.direction);
	co.vh = dot_product(ray.direction, cone->vector);
	co.vw = dot_product(ray.direction, co.w);
	co.wh = dot_product(co.w, cone->vector);
	co.ww = dot_product(co.w, co.w);
	co.m = (cone->radius * cone->radius) / (cone->height * cone->height);
	co.a = co.vv - co.m * (co.vh * co.vh) - (co.vh * co.vh);
	co.b = 2 * (co.vw - co.m * (co.vh * co.wh) - (co.vh * co.wh));
	co.c = co.ww - co.m * (co.wh * co.wh) - (co.wh * co.wh);
	co.det = co.b * co.b - 4. * co.a * co.c;
	return (intercept_cone2(co, cone, ray));
}

t_point		multiply_vec(t_point p, double n)
{
	p.x *= n;
	p.y *= n;
	p.z *= n;
	return (p);
}
