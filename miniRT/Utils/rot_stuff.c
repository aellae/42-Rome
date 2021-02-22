/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:52:53 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:52:55 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_point	calculate_rot(t_point *c2, t_point *c3, t_point rot, t_point to)
{
	t_point	c1;
	t_point	v;
	float	c;
	float	s;
	float	r;

	v = cross_product(to, rot);
	c = dot_product(rot, to);
	s = pow(vlen(v), 2);
	r = ((1 - c) / s);
	c1 = create_point(-r * (pow(v.y, 2) + pow(v.z, 2)) + 1, r * v.x *
				v.y - v.z, r * v.x * v.z + v.y);
	(*c2) = create_point(r * v.x * v.y + v.z, -r * (pow(v.x, 2) +
					pow(v.z, 2)) + 1, r * v.y * v.x - v.x);
	(*c3) = create_point(r * v.x * v.z - v.y, r * v.y * v.z - v.x, -r *
					(pow(v.x, 2) + pow(v.y, 2)) + 1);
	return (c1);
}

t_point	apply_rot(t_point pos, t_point dir, t_point rot)
{
	t_point	c1;
	t_point	c2;
	t_point	c3;
	t_point	prev;

	if (dir.x == rot.x && dir.y == rot.y && rot.z == dir.z)
		return (pos);
	if (dir.x == 0 && dir.y < 0 && dir.z == 0)
		pos = create_point(pos.x, pos.y, -pos.z);
	else if (!(dir.x == 0 && dir.y != 0 && dir.z == 0))
	{
		prev = pos;
		c1 = calculate_rot(&c2, &c3, rot, dir);
		pos = create_point(dot_product(c1, prev),
				dot_product(c2, prev), dot_product(c3, prev));
	}
	return (pos);
}
