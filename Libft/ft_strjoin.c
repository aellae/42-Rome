/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 09:08:49 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/12 09:08:58 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	len;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen((char *)s1) + ft_strlen(((char *)s2)) + 1;
	if (!(ret = (char *)malloc(len)))
		return (0);
	i = 0;
	ft_strlcpy(ret, s1, len);
	ft_strlcat(ret, s2, len);
	return (ret);
}
