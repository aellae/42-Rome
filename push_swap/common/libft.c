/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 09:07:46 by etaranti          #+#    #+#             */
/*   Updated: 2021/03/27 09:07:49 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_strlen(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_putnbr(int n)
{
	unsigned int nb;

	if (n < 0)
	{
		nb = n * (-1);
		write(1, "-", 1);
	}
	else
		nb = n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar(nb + '0');
}

int		ft_atoi(char *n)
{
	unsigned int	nb;
	int				sign;

	nb = 0;
	sign = 1;
	while (*n == ' ' || ((*n >= 9) && (*n <= 13)))
		n++;
	if (*n == '-' || *n == '+')
	{
		if (*n == '-')
			sign = -1;
		n++;
	}
	while (*n <= '9' && *n >= '0')
	{
		nb = nb * 10 + (*n - '0');
		n++;
		if (nb > 2147483647)
			break ;
	}
	if ((nb == 2147483648 && sign == -1) || nb < 2147483648)
		return (nb * sign);
	if (sign == 1)
		return (-1);
	return (0);
}

void	putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)s2[i]);
}
