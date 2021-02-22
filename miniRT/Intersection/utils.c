/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:48:16 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:48:19 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intersect	no_intersect(void)
{
	t_intersect ret;

	ret.color = paint(0, 0, 0, 0);
	ret.distance = MAX_DISTANCE;
	return (ret);
}
