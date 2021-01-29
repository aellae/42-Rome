/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 07:46:10 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/12 07:46:12 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t index;

	index = 0;
	while (dst[index] && index < size)
		index++;
	while (index + 1 < size && *src)
		dst[index++] = *src++;
	if (index < size)
		dst[index] = 0;
	while (*src++)
		index++;
	return (index);
}
