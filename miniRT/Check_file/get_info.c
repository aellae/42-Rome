/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:44:04 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:44:05 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			get_resolution(char *line)
{
	int i;

	i = 2;
	if (g_xres != 0 || g_yres != 0)
		return (-1);
	if ((g_xres = atoi(&line[i])) <= 0)
		return (-1);
	i = skip_spaces_and_numbers(line, i);
	if ((g_yres = atoi(&line[i])) <= 0)
		return (-1);
	i = skip_spaces_and_numbers(line, i);
	while (line[i])
	{
		if ((line[i] != ' ' || (line[i] < 9 || line[i] > 13)))
			return (-1);
		i++;
	}
	return (1);
}

int			get_ambient(char *line)
{
	int i;

	i = 2;
	if (g_ambient.intensity != -1)
		return (-1);
	if (!((g_ambient.intensity = fake_atod(&line[i])) >= 0
		&& g_ambient.intensity <= 1))
		return (-1);
	i = skip_float_and_spaces(line, i);
	if (read_color(line, &(g_ambient.color), &i) == -1)
		return (-1);
	while (line[i])
	{
		if ((line[i] != ' ' || (line[i] < 9 || line[i] > 13)))
			return (-1);
		i++;
	}
	return (1);
}

t_camera	*new_camera(void)
{
	t_camera *camera;

	camera = malloc(sizeof(t_camera));
	camera->next = 0;
	return (camera);
}

int			get_camera(char *line)
{
	int			i;
	t_camera	*curr_camera;

	if ((curr_camera = get_currcamera()) == 0)
		return (-1);
	i = 1;
	if (read_point(line, &i, &(curr_camera->center)) == -1 ||
		read_point(line, &i, &(curr_camera->direction)) == -1 ||
		vlen(curr_camera->direction) == 0)
		return (-1);
	if (vlen(curr_camera->direction) != 1)
		curr_camera->direction = normalize_vector(curr_camera->direction);
	if ((curr_camera->fov = atoi(&line[i])) <= 0 || curr_camera->fov >= 180)
		return (-1);
	curr_camera->fov *= M_PI / 180;
	i = skip_spaces_and_numbers(line, i);
	if (line[i] != 0)
		return (-1);
	return (1);
}

int			create_light(char *line)
{
	t_light	*new_light;
	t_light	*curr;
	int		i;

	new_light = malloc(sizeof(t_light));
	i = 1;
	if (read_point(line, &i, &(new_light->center)) == -1)
		return (free_error(new_light));
	if ((new_light->intensity = fake_atod(&line[i])) <= 0)
		return (free_error(new_light));
	i = skip_float_and_spaces(line, i);
	if (read_color(line, &(new_light->color), &i) == -1 || (line[i] != 0))
		return (free_error(new_light));
	new_light->next = 0;
	if (g_lights == 0)
	{
		g_lights = new_light;
		return (1);
	}
	curr = g_lights;
	while (curr && curr->next)
		curr = curr->next;
	curr->next = new_light;
	return (1);
}
