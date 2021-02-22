/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:43:28 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:43:32 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	create_sphere(char *line)
{
	int			i;
	t_sphere	*sp;

	if (!(sp = malloc(sizeof(t_sphere))))
		return (-1);
	i = 2;
	if (read_point(line, &i, &(sp->center)) == -1)
		return (free_error(sp));
	if ((sp->diameter = fake_atod(&line[i])) <= 0)
		return (free_error(sp));
	i = skip_float_and_spaces(line, i);
	if (read_color(line, &(sp->color), &i) == -1)
		return (free_error(sp));
	while (line[i])
	{
		if ((line[i] != ' ' || (line[i] < 9 || line[i] > 13)))
			return (free_error(sp));
		i++;
	}
	if (new_object(sp, 's') == -1)
		return (free_error(sp));
	sp->color.t = 1;
	return (1);
}

int	create_plane(char *line)
{
	int		i;
	t_plane	*pl;

	if (!(pl = malloc(sizeof(t_plane))))
		return (-1);
	i = 2;
	if (read_point(line, &i, &(pl->center)) == -1)
		return (free_error(pl));
	if (read_point(line, &i, &(pl->vector)) == -1)
		return (free_error(pl));
	if (vlen(pl->vector) != 1)
		pl->vector = normalize_vector(pl->vector);
	if (read_color(line, &(pl->color), &i) == -1)
		return (free_error(pl));
	while (line[i])
	{
		if ((line[i] != ' ' || (line[i] < 9 || line[i] > 13)))
			return (free_error(pl));
		i++;
	}
	if (new_object(pl, 'p') == -1)
		return (free_error(pl));
	pl->color.t = 1;
	return (1);
}

int	create_square(char *line)
{
	int			i;
	t_square	*sq;

	if (!(sq = malloc(sizeof(t_square))))
		return (-1);
	i = 2;
	if (read_point(line, &i, &(sq->center)) == -1 ||
			read_point(line, &i, &(sq->vector)) == -1)
		return (free_error(sq));
	if ((sq->side = fake_atod(&line[i])) <= 0)
		return (free_error(sq));
	if (vlen(sq->vector) != 1)
		sq->vector = normalize_vector(sq->vector);
	i = skip_float_and_spaces(line, i);
	if (read_color(line, &(sq->color), &i) == -1)
		return (free_error(sq));
	while (line[i])
	{
		if ((line[i] != ' ' || (line[i] < 9 || line[i] > 13)))
			return (free_error(sq));
		i++;
	}
	if ((sq->color.t = 1) && new_object(sq, 'q') == -1)
		return (free_error(sq));
	return (1);
}

int	create_triangle(char *line)
{
	int			i;
	t_triangle	*tr;

	if (!(tr = malloc(sizeof(t_triangle))))
		return (-1);
	i = 2;
	if (read_point(line, &i, &(tr->point_a)) == -1)
		return (free_error(tr));
	if (read_point(line, &i, &(tr->point_b)) == -1)
		return (free_error(tr));
	if (read_point(line, &i, &(tr->point_c)) == -1)
		return (free_error(tr));
	if (read_color(line, &(tr->color), &i) == -1)
		return (free_error(tr));
	while (line[i])
	{
		if ((line[i] != ' ' || (line[i] < 9 || line[i] > 13)))
			return (free_error(tr));
		i++;
	}
	if (new_object(tr, 't') == -1)
		return (free_error(tr));
	tr->color.t = 1;
	return (1);
}

int	create_cylinder(char *line)
{
	int			i;
	t_cylinder	*cy;

	if (!(cy = malloc(sizeof(t_cylinder))))
		return (-1);
	i = 2;
	if (read_point(line, &i, &(cy->center)) == -1)
		return (free_error(cy));
	if (read_point(line, &i, &(cy->vector)) == -1)
		return (free_error(cy));
	if (vlen(cy->vector) != 1)
		cy->vector = normalize_vector(cy->vector);
	if ((cy->diameter = fake_atod(&line[i])) <= 0)
		return (free_error(cy));
	i = skip_float_and_spaces(line, i);
	if ((cy->height = fake_atod(&line[i])) <= 0)
		return (free_error(cy));
	i = skip_float_and_spaces(line, i);
	if (read_color(line, &(cy->color), &i) == -1)
		return (free_error(cy));
	if (skip_spaces(line, i) == -1)
		return (free_error(cy));
	if ((cy->color.t = 1) && new_object(cy, 'c') == -1)
		return (free_error(cy));
	return (1);
}
