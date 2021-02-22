/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:49:10 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:49:12 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		close_window(t_vars *vars)
{
	free_all();
	mlx_destroy_window(vars->mlx, vars->win);
	exit(1);
}

void	close_w(int keycode, t_vars *vars)
{
	if (keycode == 53)
		close_window(vars);
	if (keycode == 49)
	{
		g_camera = g_camera->next;
		mlx_destroy_window(vars->mlx, vars->win);
		create_window(0);
	}
}

void	move_camera_center(int keycode, t_vars *vars)
{
	if (keycode == 124)
		g_camera->center.x += 1;
	if (keycode == 123)
		g_camera->center.x -= 1;
	if (keycode == 126)
		g_camera->center.y += 1;
	if (keycode == 125)
		g_camera->center.y -= 1;
	if (keycode == 115)
		g_camera->center.z += 1;
	if (keycode == 119)
		g_camera->center.z -= 1;
	if (keycode == 124 || keycode == 123 || keycode == 125 ||
		keycode == 126 || keycode == 115 || keycode == 119)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		create_window(0);
	}
}

int		key_hook(int keycode, t_vars *vars)
{
	close_w(keycode, vars);
	move_camera_center(keycode, vars);
	move_camera_direction(keycode, vars);
	move_objects(keycode, vars);
	return (1);
}
