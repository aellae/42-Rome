/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:44:26 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:44:29 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			filter(char *line)
{
	int i;

	i = 1;
	while (line[i] == ' ' || (line[i] <= 13 && line[i] >= 9))
		i++;
	i++;
	if (line[i - 1] == 's')
		g_filter[0] = 's';
	else if (line[i - 1] == 'r')
		g_filter[0] = 'r';
	else if (line[i - 1] == 'b')
		g_filter[0] = 'b';
	else if (line[i - 1] == 'g')
		g_filter[0] = 'g';
	else if (line[i - 1] == 't')
		g_filter[0] = 't';
	else
		return (-1);
	while (line[i])
	{
		if ((line[i] != ' ' || (line[i] < 9 || line[i] > 13)))
			return (-1);
		i++;
	}
	return (1);
}

int			check_ali(char *line)
{
	int i;

	i = 2;
	while (line[i])
	{
		if (line[i] == ' ' || (line[i] <= 13 && line[i] >= 9))
			i++;
		else
			return (-1);
	}
	g_aa = 1;
	return (1);
}

int			new_object(void *obj, char type)
{
	t_object *new;
	t_object *curr;

	if (!(new = malloc(sizeof(t_object))))
		return (-1);
	new->type = type;
	new->object = obj;
	new->next = 0;
	if (!g_objects)
		g_objects = new;
	else
	{
		curr = g_objects;
		while (curr && curr->next)
			curr = curr->next;
		curr->next = new;
	}
	return (1);
}

t_camera	*get_currcamera(void)
{
	t_camera *curr_camera;

	if (!g_camera)
	{
		if (!(g_camera = new_camera()))
			return (0);
		curr_camera = g_camera;
	}
	else
	{
		curr_camera = g_camera;
		while (curr_camera && curr_camera->next)
			curr_camera = curr_camera->next;
		curr_camera->next = new_camera();
		curr_camera = curr_camera->next;
	}
	return (curr_camera);
}
