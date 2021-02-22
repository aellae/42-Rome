/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:51:58 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:52:01 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_FILE_H
# define CHECK_FILE_H

# include "struct.h"

int			read_point(char *line, int *i, t_point *ret);
int			read_color(char *line, t_color *color, int *i);
int			read_input(int fd);

double		fake_atod(char *line);
t_point		normalize_vector(t_point point);
t_point		diff(t_point one, t_point two);
int			new_object(void *obj, char type);

double		vlen(t_point point);
int			free_error(void *todelete);
double		point_dist(t_point a, t_point b);

int			skip_spaces(char *line, int i);
int			skip_spaces_and_numbers(char *line, int i);
int			skip_numbers(char *line, int i);
int			skip_float_and_spaces(char *line, int i);

int			get_resolution(char *line);
int			get_ambient(char *line);
int			get_camera(char *line);
t_camera	*get_currcamera(void);
int			create_light(char *line);
int			create_sphere(char *line);
int			create_plane(char *line);
int			create_square(char *line);
int			create_triangle(char *line);
int			create_cylinder(char *line);
t_camera	*new_camera(void);
int			filter(char *line);

int			create_cube(char *line);
int			create_pyramid(char *line);
int			create_cu_tr(t_cube *cu);
int			create_py_tr(t_pyramid *py);
int			check_base(t_point a, t_point b, t_point c, t_point d);
int			create_cone(char *line);
int			check_ali(char *line);

int			create_c_plane(char *line);
int			create_c_sphere(char *line);
int			create_r_plane(char *line);
int			create_plight(char *line);
#endif
