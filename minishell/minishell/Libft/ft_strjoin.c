/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 09:32:33 by ade-feli          #+#    #+#             */
/*   Updated: 2021/01/14 09:32:34 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	len_s1;
	unsigned int	total;
	unsigned int	i;
	char			*ret;

	len_s1 = ft_strlen(s1);
	i = 0;
	total = len_s1 + ft_strlen(s2) + 1;
	ret = malloc(total);
	if (!ret)
		return (0);
	while (i < len_s1)
	{
		ret[i] = s1[i];
		i++;
	}
	while (i < total - 1)
	{
		ret[i] = s2[i - len_s1];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

char	*ft_elbowing(char *to_be_changed, char to_inser, int cursor)
{
	char *right;
	char *left;
	char *changed;

	right = &to_be_changed[cursor];
	left = ft_strdup(to_be_changed);
	left[cursor] = 0;
	left = charjoin(left, to_inser, cursor);
	changed = ft_strjoin(left, right);
	return (changed);
}
