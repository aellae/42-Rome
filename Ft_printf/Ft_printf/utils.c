/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:32:07 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/21 09:35:48 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar(char c)
{
	write(1, &c, 1);
	(g_var->ret)++;
}

int		add_zero(int len)
{
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	if (!(tmp = malloc(g_var->precision + 1)))
		return (-1);
	while ((i + len) < g_var->precision)
		tmp[i++] = '0';
	j = 0;
	while ((g_var->save)[j])
		tmp[i++] = (g_var->save)[j++];
	tmp[i] = 0;
	if (g_var->save)
	{
		free(g_var->save);
		g_var->save = 0;
	}
	g_var->save = tmp;
	return (0);
}

char	*ft_utoa(unsigned int n)
{
	int				len;
	char			*str;
	unsigned int	tmp;

	len = 0;
	tmp = n;
	if (n == 0)
		len = 1;
	else
		while (tmp)
		{
			tmp /= 10;
			len++;
		}
	if (!(str = malloc(len + 1)))
		return (0);
	str[len] = 0;
	str[--len] = '0' + (n % 10);
	while (n /= 10)
		str[--len] = '0' + (n % 10);
	return (str);
}

char	*ft_hex_itoa(unsigned int n, const char *base)
{
	int				len;
	char			*str;
	unsigned int	tmp;

	len = 0;
	tmp = n;
	if (n == 0)
		len = 1;
	else
		while (tmp)
		{
			tmp /= 16;
			len++;
		}
	if (!(str = malloc(len + 1)))
		return (0);
	str[len] = 0;
	str[--len] = base[n % 16];
	while (n /= 16)
		str[--len] = base[n % 16];
	return (str);
}

char	*ft_hex_long_itoa(size_t n, const char *base)
{
	int				len;
	char			*str;
	size_t			tmp;

	len = 0;
	tmp = n;
	if (n == 0)
		len = 1;
	else
		while (tmp)
		{
			tmp /= 16;
			len++;
		}
	if (!(str = malloc(len + 1)))
		return (0);
	str[len] = 0;
	str[--len] = base[n % 16];
	while (n /= 16)
		str[--len] = base[n % 16];
	return (str);
}
