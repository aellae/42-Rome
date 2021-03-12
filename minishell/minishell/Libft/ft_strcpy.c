/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:25:23 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/01 17:25:24 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy(char *dst, const char *src)
{
	int	index;

	index = 0;
	if (!dst && !src)
		return ;
	while (src[index])
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = 0;
}
