/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:48:11 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:48:12 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect	intercept_triangle(t_triangle *tr, t_ray ray)
{
	double				det;
	t_inter_triangle	t;
	t_intersect			ret;

	t.e2 = diff(tr->point_a, tr->point_b);
	t.e1 = diff(tr->point_a, tr->point_c);
	t.n = cross_product(t.e1, t.e2);
	det = -1 * dot_product(ray.direction, t.n);
	t.inv_det = 1 / det;
	t.ao = diff(tr->point_a, ray.origin);
	t.dao = cross_product(t.ao, ray.direction);
	t.u = (dot_product(t.e2, t.dao) * t.inv_det);
	t.v = dot_product(t.e1, t.dao) * (t.inv_det) * -1;
	t.t = dot_product(t.ao, t.n) * t.inv_det;
	if ((t.t >= 0) && (t.u >= 0) && (t.v >= 0) && (t.u + t.v <= 1))
	{
		ret.distance = t.t;
		ret.color = tr->color;
		return (ret);
	}
	ret = no_intersect();
	return (ret);
}
