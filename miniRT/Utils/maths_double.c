/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:52:43 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:52:44 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	vlen(t_point point)
{
	return (sqrt(point.x * point.x + point.y * point.y + point.z * point.z));
}

double	point_dist(t_point a, t_point b)
{
	return (vlen(diff(a, b)));
}

t_point	move_on_ray(t_point p, t_point dir, double dist)
{
	t_point ret;

	ret.x = p.x + (dir.x * dist);
	ret.y = p.y + (dir.y * dist);
	ret.z = p.z + (dir.z * dist);
	return (ret);
}

double	dot_product(t_point a, t_point b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_point	minus(t_point t)
{
	t.x = -t.x;
	t.y = -t.y;
	t.z = -t.z;
	return (t);
}
