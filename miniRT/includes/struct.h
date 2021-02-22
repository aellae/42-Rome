/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:52:14 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:52:16 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_point
{
	double x;
	double y;
	double z;
}				t_point;

typedef struct	s_color
{
	int t;
	int r;
	int g;
	int b;

}				t_color;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_sphere
{
	t_point		center;
	double		diameter;
	t_color		color;
}				t_sphere;

typedef struct	s_plane
{
	t_point		center;
	t_point		vector;
	t_color		color;
}				t_plane;

typedef struct	s_square
{
	t_point			center;
	t_point			vector;
	double			side;
	t_color			color;
}				t_square;

typedef struct	s_triangle
{
	t_point			point_a;
	t_point			point_b;
	t_point			point_c;
	t_color			color;
}				t_triangle;

typedef struct	s_cylinder
{
	t_point		center;
	t_point		vector;
	double		diameter;
	double		height;
	t_color		color;
}				t_cylinder;

typedef struct	s_cone
{
	t_point		center;
	t_point		vector;
	double		height;
	double		radius;
	t_color		color;
}				t_cone;

typedef struct	s_ambient
{
	double	intensity;
	t_color	color;
}				t_ambient;

typedef struct	s_camera
{
	t_point			center;
	t_point			direction;
	double			fov;
	struct s_camera	*next;
}				t_camera;

typedef struct	s_light
{
	t_point			center;
	double			intensity;
	t_color			color;
	struct s_light	*next;
}				t_light;

typedef struct	s_object
{
	char			type;
	void			*object;
	struct s_object	*next;
}				t_object;

typedef struct	s_ray
{
	t_point origin;
	t_point direction;
}				t_ray;

typedef struct	s_intesect
{
	double	distance;
	t_color	color;
}				t_intersect;

typedef struct	s_inter_triangle
{
	t_point	n;
	double	inv_det;
	t_point	ao;
	t_point	dao;
	t_point	e1;
	t_point	e2;
	double	u;
	double	v;
	double	t;
}				t_inter_triangle;

typedef struct	s_inter_cyl
{
	t_intersect	ret;
	t_point		pa;
	t_point		pb;
	t_point		ca;
	t_point		oc;
	double		caca;
	double		caoc;
	double		card;
	double		a;
	double		b;
	double		c;
	double		h;
}				t_inter_cyl;

typedef struct	s_get_pixel
{
	t_color		c;
	double		distance;
	t_ray		ray;
	t_object	*closest;
	t_ambient	light;
	t_point		intersect;
	t_point		norm;
}				t_get_pixel;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_pyramid
{
	t_point tip;
	t_point base_a;
	t_point base_b;
	t_point base_c;
	t_point base_d;
	t_color color;
}				t_pyramid;

typedef struct	s_cube
{
	t_point	up_a;
	t_point up_b;
	t_point up_c;
	t_point up_d;
	t_point	down_a;
	t_point down_b;
	t_point down_c;
	t_point down_d;
	t_color color;
}				t_cube;

typedef	struct	s_inter_co
{
	t_point	w;
	double	vv;
	double	vh;
	double	vw;
	double	wh;
	double	ww;
	double	m;
	double	a;
	double	b;
	double	c;
	double	det;

}				t_inter_co;

typedef struct	s_plight
{
	t_point		center;
	t_point		vector;
	double		intensity;
	t_color		color;
}				t_plight;

#endif
