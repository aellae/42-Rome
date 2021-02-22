/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:46:03 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:46:31 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			create_trgb(t_color color)
{
	if (color.t == 1)
		return (1 << 24 | color.r << 16 | color.g << 8 | color.b);
	else
		return (0);
}

t_color		paint(int r, int g, int b, int t)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.t = t;
	return (color);
}

t_color		illuminate(t_color c, t_ambient light)
{
	t_color final;

	final.r = (c.r - 255 + light.color.r) * light.intensity;
	final.g = (c.g - 255 + light.color.g) * light.intensity;
	final.b = (c.b - 255 + light.color.b) * light.intensity;
	final.r = final.r > 0 ? final.r : 0;
	final.g = final.g > 0 ? final.g : 0;
	final.b = final.b > 0 ? final.b : 0;
	return (final);
}

t_ambient	mix_colors(t_ambient dest, t_color color, double intensity)
{
	t_ambient ret;

	ret.color.r = dest.color.r + (color.r) * intensity;
	ret.color.g = dest.color.g + (color.g) * intensity;
	ret.color.b = dest.color.b + (color.b) * intensity;
	ret.intensity = 1;
	ret.color.r = ret.color.r > 255 ? 255 : ret.color.r;
	ret.color.g = ret.color.g > 255 ? 255 : ret.color.g;
	ret.color.b = ret.color.b > 255 ? 255 : ret.color.b;
	return (ret);
}
