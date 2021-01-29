/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 07:45:43 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/12 07:45:45 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t i;

	i = 0;
	if (!dest && !src)
		return (0);
	if ((src + len) >= dest && (src + len) <= (dest + len))
		while (len--)
			*(unsigned char *)(dest + len) = *(unsigned char *)(src + len);
	else
		while (i < len)
		{
			*(unsigned char *)(dest + i) = *(unsigned char *)(src + i);
			i++;
		}
	return (dest);
}
