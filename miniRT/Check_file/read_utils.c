/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 12:44:33 by etaranti          #+#    #+#             */
/*   Updated: 2021/02/14 12:45:17 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		decimal_len(int n)
{
	int len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

double	fake_atod(char *line)
{
	int		i;
	double	ret;
	int		zeros;
	int		sign;

	i = 0;
	zeros = 0;
	sign = 1;
	while (line[i] && (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
		i++;
	if (line[i] == '-')
		sign = -1;
	ret = abs(atoi(&line[i]));
	i = skip_numbers(line, i);
	if (line[i] == '.')
	{
		while (line[++i] == '0')
			zeros++;
		if (!(line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
			ret += atoi(&line[i]) /
				(__exp10(zeros + decimal_len(atoi(&line[i]))));
	}
	return (ret * sign);
}

int		read_point(char *line, int *i, t_point *ret)
{
	(*ret).x = fake_atod(&line[*i]);
	*i = skip_float_and_spaces(line, *i);
	if (line[(*i)++] != ',')
		return (-1);
	(*ret).y = fake_atod(&line[*i]);
	*i = skip_float_and_spaces(line, *i);
	if (line[(*i)++] != ',')
		return (-1);
	(*ret).z = fake_atod(&line[*i]);
	*i = skip_float_and_spaces(line, *i);
	return (1);
}

int		read_color(char *line, t_color *color, int *i)
{
	if (((*color).r = atoi(&line[*i])) < 0 || (*color).r > 255)
		return (-1);
	*i = skip_numbers(line, *i);
	if (line[(*i)++] != ',')
		return (-1);
	if (((*color).g = atoi(&line[*i])) < 0 || (*color).g > 255)
		return (-1);
	*i = skip_numbers(line, *i);
	if (line[(*i)++] != ',')
		return (-1);
	if (((*color).b = atoi(&line[*i])) < 0 || (*color).b > 255)
		return (-1);
	*i = skip_numbers(line, *i);
	return (1);
}

int		free_error(void *todelete)
{
	free(todelete);
	return (-1);
}
