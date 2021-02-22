/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:53:19 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:53:25 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	generate_image(t_data *img)
{
	double	x;
	double	y;
	int		color;

	y = 0;
	while (y < g_yres)
	{
		x = 0;
		while (x < g_xres)
		{
			if (g_aa)
			{
				color = antiali(get_pixel_color(x, y),
					get_pixel_color(x + 0.5, y), get_pixel_color(x, y + 0.5),
					get_pixel_color(x + 0.5, y + 0.5));
				my_mlx_pixel_put(img, x, y, color);
			}
			else
				my_mlx_pixel_put(img, x, y, get_pixel_color(x, y));
			x++;
		}
		y++;
	}
}

void	max_res(void *mlx)
{
	int		screen_res[2];
	double	reduction;

	mlx_get_screen_size(mlx, &screen_res[0], &screen_res[1]);
	if (g_xres > (unsigned int)screen_res[0])
	{
		reduction = (double)g_xres / (double)screen_res[0];
		g_xres = (unsigned int)screen_res[0];
		g_yres /= reduction;
	}
	if (g_yres > (unsigned int)screen_res[1])
	{
		reduction = (double)g_yres / (double)screen_res[1];
		g_yres = (unsigned int)screen_res[1];
		g_xres /= reduction;
	}
}

void	create_window2(t_vars vars, t_data img, int save, t_data img2)
{
	if (g_filter[0] == 't')
	{
		g_filter[1] = 1;
		g_camera->center.x += 0.5;
		g_filter[0] = 'r';
		generate_image(&img2);
		fusion_images(&img, &img2);
		g_filter[0] = 't';
	}
	if (save)
	{
		save_image_to_bmp_file(&img);
		printf(GREEN"\tImage saved!\n\n"RESET);
		return ;
	}
	vars.win = mlx_new_window(vars.mlx, g_xres, g_yres, "miniRT");
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	print_legenda();
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 17, 1L << 2, close_window, &vars);
	mlx_hook(vars.win, 4, 0, mouse_click, &vars);
	mlx_loop(vars.mlx);
}

void	create_window(int save)
{
	t_data	img;
	t_vars	vars;
	t_data	img2;
	int		hor;
	int		ver;

	vars.mlx = mlx_init();
	max_res(vars.mlx);
	g_texture.img = mlx_xpm_file_to_image(vars.mlx,
						"skybox/nebula.xpm", &hor, &ver);
	g_texture.addr = mlx_get_data_addr(g_texture.img,
		&g_texture.bits_per_pixel, &g_texture.line_length, &g_texture.endian);
	img.img = mlx_new_image(vars.mlx, g_xres, g_yres);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
									&img.line_length, &img.endian);
	img2.img = mlx_new_image(vars.mlx, g_xres, g_yres);
	img2.addr = mlx_get_data_addr(img2.img, &img2.bits_per_pixel,
									&img2.line_length, &img2.endian);
	generate_image(&img);
	create_window2(vars, img, save, img2);
}
