/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:46:24 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:46:25 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color		get_rgb(int trgb)
{
	t_color ret;

	ret.r = trgb >> 16 & (0xFF);
	ret.g = trgb >> 8 & (0xFF);
	ret.b = trgb & 0xFF;
	ret.t = trgb >> 24 & (0xFF);
	return (ret);
}

t_color		apply_filter2(t_color c)
{
	double filter;

	if (g_filter[0] == 'b')
	{
		filter = (c.r + c.g + c.b) / 3;
		c = paint(0, 0, filter, 1);
	}
	if (g_filter[0] == 't' && g_filter[0] == 0)
	{
		filter = c.r / 2;
		c = paint(0, c.g, c.b, 1);
		c.g = c.g > 255 ? 255 : c.g;
		c.b = c.b > 255 ? 255 : c.b;
	}
	return (c);
}

t_color		apply_filter(t_color c)
{
	double filter;
	double red;
	double green;
	double blue;

	if (g_filter[0] == 's')
	{
		filter = (c.r + c.g + c.r) / 3;
		red = 0.78 * filter + 55.9;
		green = (0.827 * filter + 43.9) * 235 / 255;
		blue = (0.882 * filter + 29.98) * 181 / 255;
		c = paint(red, green, blue, 1);
	}
	if (g_filter[0] == 'r')
	{
		filter = (c.r + c.g + c.b) / 3;
		c = paint(c.r, 0, 0, 1);
	}
	if (g_filter[0] == 'g')
	{
		filter = (c.r + c.g + c.b) / 3;
		c = paint(0, filter, 0, 1);
	}
	c = apply_filter2(c);
	return (c);
}

void		fusion_images(t_data *one, t_data *two)
{
	unsigned int	x;
	t_color			c1;
	t_color			c2;

	x = 0;
	while (x < g_xres * g_yres)
	{
		c1 = get_rgb(((int *)(one->addr))[x]);
		c2 = get_rgb(((int *)(two->addr))[x]);
		c1 = paint(c2.r, c1.g, c1.b, 1);
		if (((int *)(two->addr))[x])
			((int *)(one->addr))[x] = create_trgb(c1);
		x++;
	}
}
