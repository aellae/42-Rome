/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:47:59 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:48:00 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ambient	parallel_light(t_ambient ret, t_ray ray, t_point norm)
{
	t_intersect	curr_intersect;
	double		intensity;
	double		light_dist;
	t_object	*list;

	intensity = g_plight.intensity;
	ray.direction = g_plight.vector;
	light_dist = dot_product(diff(ray.origin, g_plight.center),
					g_plight.vector);
	ray.origin = move_on_ray(ray.origin, g_plight.vector, light_dist);
	list = g_objects;
	while (list)
	{
		curr_intersect = find_intersect(list, ray);
		if (fabs(curr_intersect.distance) < fabs(light_dist))
		{
			intensity = 0;
			break ;
		}
		list = list->next;
	}
	intensity *= fabs(dot_product(ray.direction, norm));
	ret = mix_colors(ret, g_plight.color, intensity);
	return (ret);
}

t_ambient	shadow_2(t_ambient ret, t_ray ray, t_point norm, t_light *light)
{
	t_intersect	curr_intersect;
	double		intensity;
	double		light_dist;
	t_object	*list;

	intensity = light->intensity;
	ray.direction = normalize_vector(diff(light->center, ray.origin));
	light_dist = vlen(diff(ray.origin, light->center));
	ray.origin = light->center;
	list = g_objects;
	while (list)
	{
		curr_intersect = find_intersect(list, ray);
		if (fabs(curr_intersect.distance) < fabs(light_dist))
		{
			intensity = 0;
			break ;
		}
		list = list->next;
	}
	intensity *= fabs(dot_product(ray.direction, norm));
	ret = mix_colors(ret, light->color, intensity);
	return (ret);
}

t_ambient	shadow_trace(t_ray ray, t_point norm)
{
	t_ambient	ret;
	t_light		*light;

	light = g_lights;
	ret.color = paint(0, 0, 0, 1);
	ray.origin = move_on_ray(ray.origin, minus(ray.direction), 0.01);
	while (light)
	{
		ret = shadow_2(ret, ray, norm, light);
		light = light->next;
	}
	if (g_plight.intensity != 0)
	{
		ret = parallel_light(ret, ray, norm);
	}
	if (g_ambient.intensity > 0)
		ret = mix_colors(ret, g_ambient.color, g_ambient.intensity);
	ret.intensity = ret.intensity > 1 ? 1 : ret.intensity;
	return (ret);
}
