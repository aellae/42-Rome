/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:58:49 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/20 17:11:59 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	d_case(const char **s)
{
	int n;

	n = va_arg(g_var->args, int);
	if (n < 0)
	{
		g_var->negative = 1;
		n *= -1;
	}
	if (!(g_var->save = ft_utoa((unsigned int)n)))
		return (-1);
	if (g_var->checkp)
		g_var->zero = ' ';
	if (prepare_print() == -1)
		return (-1);
	(*s)++;
	return (0);
}

int	s_case(const char **s)
{
	char *tmp;

	(*s)++;
	g_var->is_str = 1;
	if (!(tmp = va_arg(g_var->args, char *)))
	{
		if (printnull() == -1)
			return (-1);
	}
	else
	{
		if (!(g_var->save = malloc(ft_strlen(tmp) + 1)))
			return (-1);
		ft_strlcpy(g_var->save, tmp, ft_strlen(tmp) + 1);
	}
	if (prepare_print() == -1)
		return (-1);
	return (0);
}

int	c_case(const char **s)
{
	char *tmp;

	if (!(tmp = malloc(2)))
		return (-1);
	tmp[0] = va_arg(g_var->args, int);
	tmp[1] = 0;
	g_var->save = tmp;
	if (!(tmp[0]) && g_var->width > 0)
	{
		g_var->width -= 1;
		if (!(tmp[0]) && g_var->flag)
			ft_printchar(0);
	}
	if (prepare_print() == -1)
		return (-1);
	if (!(tmp[0]) && !(g_var->flag))
		ft_printchar(0);
	(*s)++;
	return (0);
}

int	u_case(const char **s)
{
	if (!(g_var->save = ft_utoa(va_arg(g_var->args, unsigned int))))
		return (-1);
	if (g_var->checkp)
		g_var->zero = ' ';
	if (prepare_print() == -1)
		return (-1);
	(*s)++;
	return (0);
}

int	percent_case(const char **s)
{
	(*s)++;
	g_var->is_str = 1;
	if (!(g_var->save = malloc(2)))
		return (-1);
	g_var->save[0] = '%';
	g_var->save[1] = 0;
	if (prepare_print() == -1)
		return (-1);
	return (0);
}
