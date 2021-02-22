/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:48:47 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:48:49 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_camera_direction(int keycode, t_vars *vars)
{
	if (keycode == 12)
	{
		g_camera->direction.x -= 0.05;
		g_camera->direction = normalize_vector(g_camera->direction);
	}
	if (keycode == 14)
	{
		g_camera->direction.x += 0.05;
		g_camera->direction = normalize_vector(g_camera->direction);
	}
	if (keycode == 116)
	{
		g_camera->direction.y += 0.05;
		g_camera->direction = normalize_vector(g_camera->direction);
	}
	if (keycode == 121)
	{
		g_camera->direction.y -= 0.05;
		g_camera->direction = normalize_vector(g_camera->direction);
	}
	if (keycode == 12 || keycode == 14 || keycode == 116 || keycode == 121)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		create_window(0);
	}
}

int		mouse_click(int button, int x, int y, t_vars *vars)
{
	mlx_mouse_get_pos(vars->win, &x, &y);
	if (button == 2)
	{
		if ((unsigned int)x < g_xres / 2)
			move_camera_direction(12, vars);
		else
			move_camera_direction(14, vars);
	}
	if (button == 1)
	{
		if ((unsigned int)y < g_yres / 2)
			move_camera_direction(116, vars);
		else
			move_camera_direction(121, vars);
	}
	return (1);
}
