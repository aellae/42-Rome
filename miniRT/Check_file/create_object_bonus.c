/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:43:39 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:43:41 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	create_pyramid(char *line)
{
	int			i;
	t_pyramid	*py;

	if (!(py = malloc(sizeof(t_pyramid))))
		return (-1);
	i = 2;
	if (read_point(line, &i, &(py->tip)) == -1 ||
		read_point(line, &i, &(py->base_a)) == -1 ||
		read_point(line, &i, &(py->base_b)) == -1 ||
		read_point(line, &i, &(py->base_c)) == -1 ||
		read_point(line, &i, &(py->base_d)) == -1 ||
		read_color(line, &(py->color), &i) == -1)
		return (free_error(py));
	while (line[i])
	{
		if ((line[i] != ' ' || (line[i] < 9 || line[i] > 13)))
			return (free_error(py));
		i++;
	}
	if (check_base(py->base_a, py->base_b, py->base_c, py->base_d) == -1
			|| create_py_tr(py) == -1)
		return (free_error(py));
	free(py);
	return (1);
}

int	check_multibase(t_cube *cu)
{
	create_cu_tr(cu);
	return (1);
}

int	create_cube(char *line)
{
	int		i;
	t_cube	*cu;

	if (!(cu = malloc(sizeof(t_cube))))
		return (-1);
	i = 2;
	if (read_point(line, &i, &(cu->up_a)) == -1 || read_point(line, &i,
				&(cu->up_b)) == -1 || read_point(line, &i, &(cu->up_c)) == -1 ||
			read_point(line, &i, &(cu->up_d)) == -1 ||
			read_point(line, &i, &(cu->down_a)) == -1 ||
			read_point(line, &i, &(cu->down_b)) == -1 ||
			read_point(line, &i, &(cu->down_c)) == -1 ||
			read_point(line, &i, &(cu->down_d)) == -1 ||
			read_color(line, &(cu->color), &i) == -1)
		return (free_error(cu));
	while (line[i])
	{
		if ((line[i] != ' ' || (line[i] < 9 || line[i] > 13)))
			return (free_error(cu));
		i++;
	}
	if (check_multibase(cu) == -1)
		return (free_error(cu));
	free(cu);
	return (1);
}

int	create_cone(char *line)
{
	int		i;
	t_cone	*co;

	if (!(co = malloc(sizeof(t_cone))))
		return (-1);
	i = 2;
	if (read_point(line, &i, &(co->center)) == -1 ||
		read_point(line, &i, &(co->vector)) == -1)
		return (free_error(co));
	if (vlen(co->vector) != 1)
		co->vector = normalize_vector(co->vector);
	if ((co->height = fake_atod(&line[i])) <= 0)
		return (free_error(co));
	i = skip_float_and_spaces(line, i);
	if ((co->radius = fake_atod(&line[i])) <= 0)
		return (free_error(co));
	i = skip_float_and_spaces(line, i);
	if (read_color(line, &(co->color), &i) == -1)
		return (free_error(co));
	while (line[i++])
		if ((line[i--] != ' ' || (line[i] < 9 || line[i] > 13)))
			return (free_error(co));
	if ((co->color.t = 1) && new_object(co, 'o') == -1)
		return (free_error(co));
	return (1);
}

int	create_plight(char *line)
{
	int i;

	i = 2;
	if (read_point(line, &i, &(g_plight.center)) == -1)
		return (-1);
	if ((g_plight.intensity = fake_atod(&line[i])) <= 0)
		return (-1);
	i = skip_float_and_spaces(line, i);
	if (read_point(line, &i, &(g_plight.vector)) == -1)
		return (-1);
	g_plight.vector = normalize_vector(g_plight.vector);
	if (read_color(line, &(g_plight.color), &i) == -1 || (line[i] != 0))
		return (-1);
	return (1);
}
