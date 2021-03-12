/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-feli <ade-feli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 11:18:12 by ade-feli          #+#    #+#             */
/*   Updated: 2021/03/04 12:29:15 by ade-feli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned char		ft_atochar(const char *str)
{
	unsigned char	res;
	int				sign;
	const char		*pointer;

	res = 0;
	sign = 1;
	pointer = str;
	while (*pointer == ' ' || (*pointer >= 9 && *pointer <= 13))
		pointer++;
	if (*pointer == '-')
	{
		sign *= -1;
		pointer++;
	}
	while (*pointer >= '0' && *pointer <= '9')
	{
		if (res > 0 && res * 10 + (*str - '0') < 0)
			return (sign == 1 ? -1 : 0);
		res = (res * 10) + (*pointer - '0');
		pointer++;
	}
	return (res * sign);
}
