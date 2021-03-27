/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:08:05 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:08:07 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_spaces(char *s)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == ' ')
			count++;
	}
	return (count);
}

int		absol(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

char	*charjoin(char *s, char c)
{
	char	*ret;
	int		i;
	int		max;

	if (!s)
	{
		if (!(ret = malloc(2)))
			return (0);
		ret[0] = c;
		ret[1] = 0;
		return (ret);
	}
	max = 0;
	while (s[max])
		max++;
	if (!(ret = malloc(max + 2)))
		return (0);
	i = -1;
	while (s[++i])
		ret[i] = s[i];
	ret[i++] = c;
	ret[i] = 0;
	if (s)
		free(s);
	return (ret);
}
