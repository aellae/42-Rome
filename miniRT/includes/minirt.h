/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:52:09 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:52:11 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# include "../mlx/mlx.h"
# include "../Libft/libft.h"

# include "struct.h"
# include "check_file.h"

# define MAX_DISTANCE 100000
# define SPHERE 's'
# define PLANE 'p'
# define SQUARE 'q'
# define TRIANGLE 't'
# define CYLINDER 'c'
# define CONE 'o'
# define C_SPHERE 'x'
# define C_PLANE 'y'
# define R_PLANE 'z'
# define R_SPHERE 'r'
# define RED "\033[31m"
# define GREEN "\033[32;1;4m"
# define YELLOW "\033[33;1;4m"
# define YELLOW2 "\033[33m"
# define CYAN "\033[36;1;4m"
# define CYAN2 "\033[36m"
# define RESET "\033[0m"

unsigned int	g_xres;
unsigned int	g_yres;
t_ambient		g_ambient;
t_camera		*g_camera;
t_light			*g_lights;
t_object		*g_objects;
char			g_filter[2];
int				g_aa;
t_plight		g_plight;
t_data			g_texture;
/*
** COLOR
*/
t_color		paint(int r, int g, int b, int t);
int			get_pixel_color(double x, double y);
t_color		get_rgb(int trgb);
/*
** INTERSECTION
*/
t_intersect	intercept_plane(t_plane *pl, t_ray ray);
t_intersect	intercept_square(t_square *sq, t_ray ray);
t_intersect	intercept_sphere(t_sphere *sp, t_ray ray);
t_intersect	intercept_triangle(t_triangle *tr, t_ray ray);
t_intersect	intercept_cylinder(t_cylinder *cy, t_ray ray);
/*
** RAY TRACE
*/
t_point		move_on_ray(t_point p, t_point dir, double dist);
double		ray_trace(t_ray ray, t_object **closest_obj);
t_ambient	shadow_trace(t_ray ray, t_point norm);
t_intersect find_intersect(t_object *list, t_ray ray);
/*
** VECTOR FUNCTIONS
*/
double		dot_product(t_point a, t_point b);
t_point		cross_product(t_point v1, t_point v2);
t_point		add(t_point a, t_point b);
t_point		minus(t_point t);

t_point		create_point(double x, double y, double z);
t_point		obj_normal(t_object *obj, t_ray ray, t_point intersect);

t_point		apply_rot(t_point pos, t_point dir, t_point rot);
t_point		from_image_to_space(double x, double y);

t_intersect	no_intersect(void);

void		create_window(int save);
void		move_objects(int keycode, t_vars *vars);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			close_window(t_vars *vars);
void		free_all(void);

/*
** COLORS
*/
t_ambient	mix_colors(t_ambient dest, t_color color, double intensity);
t_color		illuminate(t_color c, t_ambient light);
/*
** BONUS
*/
t_intersect intercept_cone(t_cone *cone, t_ray ray);
t_point		cone_norm(t_cone *co, t_point point);
t_color		apply_filter(t_color c);
int			create_trgb(t_color color);
int			mouse_click(int button, int x, int y, t_vars *vars);
void		move_camera_direction(int keycode, t_vars *vars);
int			save_image_to_bmp_file(t_data *img);
int			key_hook(int keycode, t_vars *vars);
void		move_triangle(char c, int sign, t_triangle *tr);
int			check_flag(char *s);
int			check_name(char *s);
void		fusion_images(t_data *one, t_data *two);
int			antiali(int a, int b, int c, int d);
void		print_legenda(void);
t_point		multiply_vec(t_point p, double n);
/*
** TEXTURE
*/
t_color		sphere_uv(t_point inter, t_sphere *sp, double dist);
t_color		plane_checkboard(t_point inter, t_plane *pl, double dist);
t_color		plane_rainbow(t_point inter, t_plane *pl, double dist);
int			create_rsphere(char *line);
#endif
