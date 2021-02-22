/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:52:48 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:52:49 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	diff(t_point one, t_point two)
{
	t_point ret;

	ret.x = two.x - one.x;
	ret.y = two.y - one.y;
	ret.z = two.z - one.z;
	return (ret);
}

t_point	normalize_vector(t_point point)
{
	t_point	vector;
	double	len;

	len = vlen(point);
	vector.x = point.x / len;
	vector.y = point.y / len;
	vector.z = point.z / len;
	return (vector);
}

t_point	create_point(double x, double y, double z)
{
	t_point a;

	a.x = x;
	a.y = y;
	a.z = z;
	return (a);
}

t_point	add(t_point a, t_point b)
{
	t_point c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_point	cross_product(t_point v1, t_point v2)
{
	t_point cross;

	cross.x = v1.y * v2.z - v1.z * v2.y;
	cross.y = v1.z * v2.x - v1.x * v2.z;
	cross.z = v1.x * v2.y - v1.y * v2.x;
	return (cross);
}
