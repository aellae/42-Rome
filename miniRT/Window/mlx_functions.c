/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:53:28 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:53:30 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		my_mlx_pixel_get(int x, int y)
{
	char *dst;

	dst = g_texture.addr + (y * g_texture.line_length + x
			* (g_texture.bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	if (color != 0)
		*(unsigned int *)dst = color;
	else
		*(unsigned int *)dst = my_mlx_pixel_get(x, y);
}
