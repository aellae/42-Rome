/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_case.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:53:51 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/20 17:30:46 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_case(const char **s)
{
	if (!(g_var->save = ft_hex_itoa(va_arg(g_var->args, int), BASE_16)))
		return (-1);
	if (g_var->checkp)
		g_var->zero = ' ';
	if (prepare_print() == -1)
		return (-1);
	(*s)++;
	return (0);
}

int	ux_case(const char **s)
{
	if (!(g_var->save = ft_hex_itoa(va_arg(g_var->args, int), BASE_16X)))
		return (-1);
	if (g_var->checkp)
		g_var->zero = ' ';
	if (prepare_print() == -1)
		return (-1);
	(*s)++;
	return (0);
}

int	p_case(const char **s)
{
	g_var->pointer = 1;
	if (!(g_var->save = ft_hex_long_itoa(va_arg(g_var->args, size_t), BASE_16)))
		return (-1);
	if (g_var->checkp)
		g_var->zero = ' ';
	if (g_var->save[2] == '0' && g_var->save[3] == 0 && g_var->precision == 0
		&& g_var->checkp == 1)
		g_var->save[2] = 0;
	if (prepare_print() == -1)
		return (-1);
	(*s)++;
	return (0);
}
