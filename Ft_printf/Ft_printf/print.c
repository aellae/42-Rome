/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:12:36 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/21 09:35:34 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	word_n_suffix_print(int len, int i)
{
	while ((g_var->save)[i])
	{
		if ((g_var->checkp && i == g_var->precision) && (g_var->is_str ||
			(*g_var->save == '0' && *(g_var->save + 1) == 0)))
			break ;
		ft_printchar((g_var->save)[i++]);
	}
	while ((g_var->flag) && len < g_var->width)
	{
		ft_printchar(g_var->zero);
		len++;
	}
}

int		prefix_print(int len)
{
	int i;

	i = 0;
	if (!(g_var->is_str) && g_var->checkp &&
		g_var->precision > len)
	{
		if (add_zero(len) == -1)
			return (-1);
		len = ft_strlen(g_var->save);
	}
	while (!(g_var->flag) && len < g_var->width)
	{
		ft_printchar(g_var->zero);
		len++;
	}
	if (g_var->zero == ' ' && g_var->negative)
		ft_printchar('-');
	if (g_var->pointer)
	{
		ft_printchar('0');
		ft_printchar('x');
	}
	word_n_suffix_print(len, i);
	return (0);
}

int		prepare_print(void)
{
	int len;

	len = ft_strlen(g_var->save);
	if (g_var->flag)
		g_var->zero = ' ';
	if (g_var->checkp && g_var->precision < len &&
		(g_var->is_str || (*g_var->save == '0' && *(g_var->save + 1) == 0)))
		len = g_var->precision;
	if (g_var->negative)
		g_var->width -= 1;
	if (g_var->pointer)
		g_var->width -= 2;
	if (g_var->zero == '0' && g_var->negative)
		ft_printchar('-');
	if (prefix_print(len) == -1)
		return (-1);
	return (0);
}

int		printnull(void)
{
	if (!(g_var->save = malloc(7)))
		return (-1);
	g_var->save[0] = '(';
	g_var->save[1] = 'n';
	g_var->save[2] = 'u';
	g_var->save[3] = 'l';
	g_var->save[4] = 'l';
	g_var->save[5] = ')';
	g_var->save[6] = 0;
	return (0);
}
