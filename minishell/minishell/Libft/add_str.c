/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:23:04 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/01 17:23:06 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*add_str(char *first, char *second)
{
	char	*ret;
	int		i;
	int		j;

	if (!(ret = malloc(ft_strlen(first) + ft_strlen(second) + 1)))
		return (0);
	i = 0;
	while (first[i])
	{
		ret[i] = first[i];
		i++;
	}
	j = 0;
	while (second[j])
		ret[i++] = second[j++];
	ret[i] = 0;
	if (first)
		free(first);
	return (ret);
}

char	*add_str_notfree(char *first, char *second)
{
	char	*ret;
	int		i;
	int		j;

	if (!(ret = malloc(ft_strlen(first) + ft_strlen(second) + 1)))
		return (0);
	i = 0;
	while (first[i])
	{
		ret[i] = first[i];
		i++;
	}
	j = 0;
	while (second[j])
		ret[i++] = second[j++];
	ret[i] = 0;
	return (ret);
}
