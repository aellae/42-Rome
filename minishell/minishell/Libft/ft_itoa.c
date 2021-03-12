/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 17:23:37 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/01 17:23:38 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		sign;
	int		tmp;

	sign = n >= 0 ? 1 : -1;
	len = 1;
	if (n < 0)
	{
		len = 2;
		n = -n;
	}
	tmp = n;
	while (tmp /= 10)
		len++;
	if (!(ret = malloc(len + 1)))
		return (0);
	ret[len] = 0;
	ret[--len] = n % 10 + '0';
	while (n /= 10)
		ret[--len] = n % 10 + '0';
	if (sign == -1)
		ret[--len] = '-';
	return (ret);
}
