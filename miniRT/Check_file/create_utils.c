/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:43:57 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:43:58 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_base(t_point a, t_point b, t_point c, t_point d)
{
	if (vlen(diff(a, c)) != vlen(diff(d, b)))
		return (-1);
	if (vlen(diff(a, b)) != vlen(diff(a, d)))
		return (-1);
	return (1);
}

int	make_tr(t_point a, t_point b, t_point c, t_color color)
{
	t_triangle	*tr;

	if (!(tr = malloc(sizeof(t_triangle))))
		return (-1);
	tr->color = color;
	tr->point_a = a;
	tr->point_b = b;
	tr->point_c = c;
	if (new_object(tr, 't') == -1)
		return (-1);
	tr->color.t = 1;
	return (1);
}

int	create_py_tr(t_pyramid *py)
{
	if (make_tr(py->tip, py->base_a, py->base_b, py->color) == -1)
		return (-1);
	if (make_tr(py->tip, py->base_c, py->base_b, py->color) == -1)
		return (-1);
	if (make_tr(py->tip, py->base_c, py->base_d, py->color) == -1)
		return (-1);
	if (make_tr(py->tip, py->base_d, py->base_a, py->color) == -1)
		return (-1);
	if (make_tr(py->base_d, py->base_a, py->base_b, py->color) == -1)
		return (-1);
	if (make_tr(py->base_c, py->base_d, py->base_b, py->color) == -1)
		return (-1);
	return (1);
}

int	create_cu_tr(t_cube *cu)
{
	if (make_tr(cu->down_a, cu->down_b, cu->down_c, cu->color) == -1)
		return (-1);
	if (make_tr(cu->down_a, cu->down_d, cu->down_c, cu->color) == -1)
		return (-1);
	if (make_tr(cu->down_a, cu->up_a, cu->up_b, cu->color) == -1)
		return (-1);
	if (make_tr(cu->down_a, cu->down_b, cu->up_b, cu->color) == -1)
		return (-1);
	if (make_tr(cu->down_b, cu->down_c, cu->up_c, cu->color) == -1)
		return (-1);
	if (make_tr(cu->down_b, cu->up_b, cu->up_c, cu->color) == -1)
		return (-1);
	if (make_tr(cu->down_d, cu->down_c, cu->up_d, cu->color) == -1)
		return (-1);
	if (make_tr(cu->down_c, cu->up_c, cu->up_d, cu->color) == -1)
		return (-1);
	if (make_tr(cu->down_d, cu->down_a, cu->up_d, cu->color) == -1)
		return (-1);
	if (make_tr(cu->up_d, cu->up_a, cu->down_a, cu->color) == -1)
		return (-1);
	if (make_tr(cu->up_a, cu->up_b, cu->up_c, cu->color) == -1)
		return (-1);
	if (make_tr(cu->up_c, cu->up_d, cu->up_a, cu->color) == -1)
		return (-1);
	return (1);
}
