/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:52:37 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:52:38 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		check_name(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] != 't' || s[i - 2] != 'r' || s[i - 3] != '.')
		return (-1);
	return (0);
}

int		check_flag(char *s)
{
	if (s[0] != '-' || s[1] != '-' ||
		s[2] != 's' || s[3] != 'a' || s[4] != 'v' || s[5] != 'e' || s[6] != 0)
		return (-1);
	return (0);
}

int		antiali(int a, int b, int c, int d)
{
	t_color ac;
	t_color bc;
	t_color cc;
	t_color dc;
	t_color	ret;

	ac = get_rgb(a);
	bc = get_rgb(b);
	cc = get_rgb(c);
	dc = get_rgb(d);
	ret.r = (ac.r + bc.r + cc.r + dc.r) / 4;
	ret.g = (ac.g + bc.g + cc.g + dc.g) / 4;
	ret.b = (ac.b + bc.b + cc.b + dc.b) / 4;
	ret.t = 1;
	return (create_trgb(ret));
}

void	print_legenda(void)
{
	printf(GREEN"\tImage ready!"RESET);
	printf("\n\n");
	printf(YELLOW"HOW TO MOVE IMAGE\n\n"RESET);
	printf(CYAN"CAMERA"RESET);
	printf(CYAN2"\n\n\t↑ ↓\t=\tmove up and down\n\t");
	printf("← →\t=\tmove left and right\n\t");
	printf("↖ ↘\t=\tmove close and move away\n\n");
	printf(CYAN"CAMERA ROTATION"RESET);
	printf(CYAN2"\n\n\t⇞ ↡\t=\tmove left and right\n\n");
	printf("\tMOUSE L\t=\tmove up and down\n\t");
	printf("MOUSE R\t=\tmove left and right"RESET);
	printf(CYAN"\n\nOBJECTS"RESET);
	printf(CYAN2"\n\n\tW S\t=\tmove up and down\n\t");
	printf("A D\t=\tmove left and right\n\n"RESET);
	printf(CYAN"CHANGE VISION\n\n"RESET);
	printf(CYAN2"\tSPACE\t=\tchange camera\n"RESET);
	printf("\n");
}
