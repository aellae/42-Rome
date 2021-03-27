/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:08:23 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:08:24 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	choose_flag(char c, char flag)
{
	if (c == 99)
	{
		if (flag == 'v')
			flag = 'b';
		else
			flag = 'c';
	}
	if (c == 118)
	{
		if (flag == 'c')
			flag = 'b';
		else
			flag = 'v';
	}
	return (flag);
}

int		skipflags(char **av, int i)
{
	char flag;

	flag = 'n';
	while (av[++i])
	{
		if (!ft_strcmp(av[i], "-c") && (flag == 'n' || flag == 'v'))
			choose_flag(99, flag);
		else if (!ft_strcmp(av[i], "-v") && (flag == 'n' || flag == 'c'))
			choose_flag(118, flag);
		else if ((!ft_strcmp(av[i], "-vc") ||
			!ft_strcmp(av[i], "-cv")) && flag == 'n')
			flag = 'b';
		else
			return (i);
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	if (!src)
		return (0);
	size = 0;
	while (src[size])
		++size;
	if (!(new = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

t_node	*last_node(t_node *s)
{
	t_node *tmp;

	if (!s)
		return (0);
	tmp = s;
	while (tmp && tmp->next)
		tmp = tmp->next;
	return (tmp);
}
