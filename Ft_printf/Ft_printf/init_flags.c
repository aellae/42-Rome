/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:53:55 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/18 15:53:57 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	flags(const char **s)
{
	if (**s == '-')
	{
		g_var->flag = 1;
		(*s)++;
		return (1);
	}
	else if (**s == '0')
	{
		g_var->zero = '0';
		(*s)++;
		return (1);
	}
	return (0);
}

int	width_case(const char **s)
{
	if (**s == '*')
	{
		g_var->width = va_arg(g_var->args, int);
		(*s)++;
		if (g_var->width < 0)
		{
			g_var->width *= -1;
			g_var->flag = 1;
		}
		return (1);
	}
	else if (**s >= '0' && **s <= '9')
	{
		g_var->width = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			(*s)++;
		return (1);
	}
	return (0);
}

int	precision_case(const char **s)
{
	if (**s == '.')
	{
		g_var->checkp = 1;
		(*s)++;
		if (**s == '*')
		{
			g_var->precision = va_arg(g_var->args, int);
			(*s)++;
			if (g_var->precision < 0)
				g_var->checkp = 0;
			return (1);
		}
		else if (**s >= '0' && **s <= '9')
		{
			g_var->precision = ft_atoi(*s);
			while ((**s >= '0' && **s <= '9'))
				(*s)++;
			return (1);
		}
	}
	return (0);
}
