/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 08:53:43 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/12 08:53:45 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s || !len || (unsigned int)ft_strlen((char *)s) <= start)
		return (ft_strdup(""));
	if (!(sub = (char *)malloc(len + 1)))
		return (0);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
