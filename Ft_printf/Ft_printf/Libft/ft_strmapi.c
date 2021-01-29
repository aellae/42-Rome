/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 12:31:25 by etaranti          #+#    #+#             */
/*   Updated: 2021/01/12 12:31:27 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*final;
	unsigned int	i;

	if (!s)
		return (0);
	if (!(final = (char *)malloc(ft_strlen((char *)s) + 1)))
		return (0);
	i = 0;
	while (s[i])
	{
		final[i] = f(i, s[i]);
		i++;
	}
	final[i] = 0;
	return (final);
}
