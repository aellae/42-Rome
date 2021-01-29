/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 08:40:59 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/12 08:41:04 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*ptr;
	size_t	index;

	len = ft_strlen((char *)s);
	if (!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	index = 0;
	while (len--)
		ptr[index++] = *s++;
	ptr[index] = 0;
	return (ptr);
}
