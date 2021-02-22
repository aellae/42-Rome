/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:52:32 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:52:34 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_objects(void)
{
	t_object *temp;

	temp = g_objects;
	while (temp)
	{
		g_objects = g_objects->next;
		if (temp->object)
		{
			free(temp->object);
			temp->object = 0;
		}
		temp->next = 0;
		free(temp);
		temp = 0;
		temp = g_objects;
	}
}

void	free_camera(void)
{
	t_camera	*temp;
	t_camera	*begin;
	int			i;

	begin = g_camera;
	temp = g_camera;
	i = 0;
	while (temp)
	{
		if (i == 1 && begin == temp)
			break ;
		g_camera = g_camera->next;
		temp->next = 0;
		free(temp);
		temp = 0;
		temp = g_camera;
		i = 1;
	}
}

void	free_lights(void)
{
	t_light *temp;

	temp = g_lights;
	while (temp)
	{
		g_lights = g_lights->next;
		temp->next = 0;
		free(temp);
		temp = 0;
		temp = g_lights;
	}
}

void	free_all(void)
{
	free_objects();
	free_camera();
	free_lights();
}
