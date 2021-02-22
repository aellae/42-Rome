/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:48:59 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:49:01 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_triangle(char c, int sign, t_triangle *tr)
{
	if (c == 'y')
	{
		tr->point_a.y += (1 * sign);
		tr->point_b.y += (1 * sign);
		tr->point_c.y += (1 * sign);
	}
	if (c == 'x')
	{
		tr->point_a.x += (1 * sign);
		tr->point_b.x += (1 * sign);
		tr->point_c.x += (1 * sign);
	}
	if (c == 'z')
	{
		tr->point_a.z += (1 * sign);
		tr->point_b.z += (1 * sign);
		tr->point_c.z += (1 * sign);
	}
}
