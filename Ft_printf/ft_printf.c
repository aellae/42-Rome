/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 08:52:40 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/18 09:36:44 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init(void)
{
	g_var->width = 0;
	g_var->checkp = 0;
	g_var->precision = 0;
	g_var->flag = 0;
	g_var->zero = ' ';
	g_var->is_str = 0;
	g_var->negative = 0;
	g_var->pointer = 0;
	g_var->save = 0;
}

int		percentagecase(const char **s)
{
	init();
	while (flags(s) || width_case(s) || precision_case(s))
		;
	if (base_case(s) == -1)
		return (-1);
	return (0);
}

int		ft_printf(const char *s, ...)
{
	t_printf curr;

	g_var = &curr;
	g_var->ret = 0;
	va_start(g_var->args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (percentagecase(&s) == -1)
				return (-1);
		}
		else
		{
			ft_putchar_fd(*s, 1);
			g_var->ret++;
			s++;
		}
	}
	va_end(g_var->args);
	return (g_var->ret);
}
