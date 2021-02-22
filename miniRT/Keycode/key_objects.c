/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:48:53 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:48:54 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_up(void)
{
	t_object *curr;

	curr = g_objects;
	while (curr)
	{
		if (curr->type == SPHERE)
			((t_sphere *)(curr->object))->center.y += 1;
		if (curr->type == PLANE)
			((t_plane *)(curr->object))->center.y += 1;
		if (curr->type == SQUARE)
			((t_square *)(curr->object))->center.y += 1;
		if (curr->type == TRIANGLE)
			move_triangle('y', +1, (t_triangle *)(curr->object));
		if (curr->type == CYLINDER)
			((t_cylinder *)(curr->object))->center.y += 1;
		if (curr->type == CONE)
			((t_cone *)(curr->object))->center.y += 1;
		curr = curr->next;
	}
}

void	move_down(void)
{
	t_object *curr;

	curr = g_objects;
	while (curr)
	{
		if (curr->type == SPHERE)
			((t_sphere *)(curr->object))->center.y -= 1;
		if (curr->type == PLANE)
			((t_plane *)(curr->object))->center.y -= 1;
		if (curr->type == SQUARE)
			((t_square *)(curr->object))->center.y -= 1;
		if (curr->type == TRIANGLE)
			move_triangle('y', -1, (t_triangle *)(curr->object));
		if (curr->type == CYLINDER)
			((t_cylinder *)(curr->object))->center.y -= 1;
		if (curr->type == CONE)
			((t_cone *)(curr->object))->center.y -= 1;
		curr = curr->next;
	}
}

void	move_right(void)
{
	t_object *curr;

	curr = g_objects;
	while (curr)
	{
		if (curr->type == SPHERE)
			((t_sphere *)(curr->object))->center.x += 1;
		if (curr->type == PLANE)
			((t_plane *)(curr->object))->center.x += 1;
		if (curr->type == SQUARE)
			((t_square *)(curr->object))->center.x += 1;
		if (curr->type == TRIANGLE)
			move_triangle('x', 1, (t_triangle *)(curr->object));
		if (curr->type == CYLINDER)
			((t_cylinder *)(curr->object))->center.x += 1;
		if (curr->type == CONE)
			((t_cone *)(curr->object))->center.x += 1;
		curr = curr->next;
	}
}

void	move_left(void)
{
	t_object *curr;

	curr = g_objects;
	while (curr)
	{
		if (curr->type == SPHERE)
			((t_sphere *)(curr->object))->center.x -= 1;
		if (curr->type == PLANE)
			((t_plane *)(curr->object))->center.x -= 1;
		if (curr->type == SQUARE)
			((t_square *)(curr->object))->center.x -= 1;
		if (curr->type == TRIANGLE)
			move_triangle('x', -1, (t_triangle *)(curr->object));
		if (curr->type == CYLINDER)
			((t_cylinder *)(curr->object))->center.x -= 1;
		if (curr->type == CONE)
			((t_cone *)(curr->object))->center.x -= 1;
		curr = curr->next;
	}
}

void	move_objects(int keycode, t_vars *vars)
{
	t_object *curr;

	curr = g_objects;
	if (keycode == 13)
		move_up();
	if (keycode == 1)
		move_down();
	if (keycode == 0)
		move_left();
	if (keycode == 2)
		move_right();
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		create_window(0);
	}
}
