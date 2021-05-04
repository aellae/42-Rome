/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:25:11 by etaranti          #+#    #+#             */
/*   Updated: 2021/04/28 11:25:13 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + (str[i++] - '0');
	return (num * sign);
}

long	ft_time(void)
{
	struct timeval	te;

	gettimeofday(&te, NULL);
	return (te.tv_sec * 1000 + te.tv_usec / 1000);
}

void	ft_usleep(int length)
{
	long	time;

	time = ft_time();
	while (ft_time() < time + length)
		usleep(length);
}

void	ft_alone(t_philo *philo)
{
	printf("0 0 has taken a fork\n");
	usleep(philo->t_die * 1000);
	printf("%d 0 is dead\n", philo->t_die);
	sem_close(philo->forks);
	sem_close(philo->state);
	sem_unlink("forks");
	sem_unlink("state");
	exit(0);
}
