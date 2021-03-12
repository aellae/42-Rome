/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:23:48 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/01 17:23:50 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (!dst && !src)
		return (0);
	while ((index + 1) < size && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	if (size != 0)
		dst[index] = 0;
	while (src[index])
		index++;
	return (index);
}

static size_t	ft_nu(char const *s, char c)
{
	size_t n;

	n = 0;
	while (*s)
	{
		if (*s != c)
		{
			n++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (n);
}

char			**ft_split(char const *s, char c)
{
	char	**final;
	char	*wbegin;
	size_t	wlen;
	size_t	i;

	if (!s || (!(final = (char **)malloc(sizeof(char *) * (ft_nu(s, c) + 1)))))
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			wbegin = (char *)s;
			while (*s && *s != c)
				s++;
			wlen = s - wbegin + 1;
			if (!(final[i] = (char *)malloc(wlen)))
				return (0);
			ft_strlcpy(final[i++], wbegin, wlen);
		}
		else
			s++;
	}
	final[i] = 0;
	return (final);
}
