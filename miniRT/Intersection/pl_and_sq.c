/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_and_sq.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:47:49 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:47:50 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect	intercept_plane(t_plane *pl, t_ray ray)
{
	t_intersect ret;
	double		den;

	ret = no_intersect();
	if (!(den = dot_product(pl->vector, ray.direction)))
		return (no_intersect());
	ret.distance = dot_product(diff(ray.origin, pl->center),
				pl->vector) / den;
	ret.color = pl->color;
	if (ret.distance < 0.01)
		return (no_intersect());
	return (ret);
}

t_plane		from_sq_to_pl(t_square sq)
{
	t_plane pl;

	pl.center = sq.center;
	pl.vector = sq.vector;
	pl.color = sq.color;
	return (pl);
}

t_intersect	intercept_square2(t_square *sq, t_point point, t_intersect pl_int)
{
	point = apply_rot(diff(point, create_point(0, 0, 0)),
						sq->vector, create_point(0, 1, 0));
	if (point.x <= (sq->side / 2) && point.x >= -(sq->side / 2))
	{
		if (point.z >= -(sq->side / 2) && point.z <= (sq->side / 2))
		{
			pl_int.color = sq->color;
			return (pl_int);
		}
	}
	pl_int = no_intersect();
	return (pl_int);
}

t_intersect	intercept_square(t_square *sq, t_ray ray)
{
	t_intersect	pl_intersect;
	t_plane		sq_plane;
	t_point		point;

	sq_plane = from_sq_to_pl(*sq);
	pl_intersect = intercept_plane(&(sq_plane), ray);
	if (pl_intersect.distance == MAX_DISTANCE)
		return (pl_intersect);
	point = move_on_ray(ray.origin, ray.direction, pl_intersect.distance);
	point = diff(sq->center, point);
	if (sq->vector.y != 1)
	{
		point = apply_rot(diff(point, create_point(0, 0, 0)),
							sq->vector, create_point(0, 0, 1));
		if (point.x <= (sq->side / 2) && point.x >= -(sq->side / 2))
			if (point.y >= -(sq->side / 2) &&
					point.y <= (sq->side / 2))
			{
				pl_intersect.color = sq->color;
				return (pl_intersect);
			}
	}
	else
		return (intercept_square2(sq, point, pl_intersect));
	return (no_intersect());
}
