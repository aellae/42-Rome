/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_object_texture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:43:50 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:43:51 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	create_c_sphere(char *line)
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
	if (new_object(sp, C_SPHERE) == -1)
		return (free_error(sp));
	sp->color.t = 1;
	return (1);
}

int	create_c_plane(char *line)
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
	if (new_object(pl, C_PLANE) == -1)
		return (free_error(pl));
	pl->color.t = 1;
	return (1);
}

int	create_r_plane(char *line)
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
	if (new_object(pl, R_PLANE) == -1)
		return (free_error(pl));
	pl->color.t = 1;
	return (1);
}

int	create_rsphere(char *line)
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
	while (line[i])
	{
		if ((line[i] != ' ' || (line[i] < 9 || line[i] > 13)))
			return (free_error(sp));
		i++;
	}
	if (new_object(sp, R_SPHERE) == -1)
		return (free_error(sp));
	return (1);
}
