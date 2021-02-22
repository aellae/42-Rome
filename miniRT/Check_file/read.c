/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:44:13 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:44:22 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_bonus(char *line)
{
	if (*line == 'c' && *(line + 1) == 'u')
		return (create_cube(line));
	else if (*line == 'f')
		return (filter(line + 1));
	else if (*line == 'c' && *(line + 1) == 'o')
		return (create_cone(line));
	else if (*line == '#' && *(line + 1) == '#')
		return (1);
	else if (*line == 'a' && *(line + 1) == 'a')
		return (check_ali(line));
	else if (*line == 'c' && *(line + 1) == 's')
		return (create_c_sphere(line));
	else if (*line == 'c' && *(line + 1) == 'p')
		return (create_c_plane(line));
	else if (*line == 'r' && *(line + 1) == 'p')
		return (create_r_plane(line));
	else if (*line == 'l' && *(line + 1) == 'l')
		return (create_plight(line));
	else if (*line == 'r' && *(line + 1) == 's')
		return (create_rsphere(line));
	else if (*line == 0)
		return (1);
	return (1);
}

int		check_line(char *line)
{
	if (*line == 'R')
		return (get_resolution(line));
	else if (*line == 'A')
		return (get_ambient(line));
	else if (*line == 'c' && (*(line + 1) == ' ' ||
		(*(line + 1) <= 13 && *(line + 1) >= 9)))
		return (get_camera(line));
	else if (*line == 'l' && (*(line + 1) == ' ' ||
		(*(line + 1) <= 13 && *(line + 1) >= 9)))
		return (create_light(line));
	else if (*line == 's' && *(line + 1) == 'p')
		return (create_sphere(line));
	else if (*line == 'p' && *(line + 1) == 'l')
		return (create_plane(line));
	else if (*line == 's' && *(line + 1) == 'q')
		return (create_square(line));
	else if (*line == 'c' && *(line + 1) == 'y')
		return (create_cylinder(line));
	else if (*line == 't' && *(line + 1) == 'r')
		return (create_triangle(line));
	else if (*line == 'p' && *(line + 1) == 'y')
		return (create_pyramid(line));
	else if (check_bonus(line) == 1)
		return (1);
	return (-1);
}

void	init_global(void)
{
	g_filter[0] = 0;
	g_filter[1] = 0;
	g_yres = 0;
	g_xres = 0;
	g_ambient.intensity = -1;
	g_lights = 0;
	g_camera = 0;
	g_aa = 0;
	g_plight.intensity = 0;
}

int		read_input(int fd)
{
	char		*line;
	int			i;
	t_camera	*curr;

	i = 1;
	init_global();
	while (i)
	{
		i = get_next_line(fd, &line);
		if (check_line(line) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
	}
	if (g_xres == 0 || g_yres == 0 || g_camera == 0)
		return (-1);
	if (g_ambient.intensity == -1)
		g_ambient.intensity = 0;
	curr = g_camera;
	while (curr && curr->next)
		curr = curr->next;
	curr->next = g_camera;
	return (1);
}
