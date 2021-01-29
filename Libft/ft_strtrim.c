/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:17:52 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/12 09:18:12 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isin(char c, char const *set)
{
	int i;

	i = -1;
	while (set[++i])
		if (set[i] == c)
			return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*begin;
	char	*end;
	size_t	len;

	if (!set || !s1)
		return (0);
	begin = (char *)s1;
	end = (char *)s1 + ft_strlen((char *)s1);
	while (*begin && ft_isin(*begin, set))
		begin++;
	while (begin < end && ft_isin(*(end - 1), set))
		end--;
	len = end - begin + 1;
	if (!(str = (char *)malloc(len)))
		return (0);
	ft_strlcpy(str, begin, len);
	return (str);
}
