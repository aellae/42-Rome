/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:23:14 by etaranti          #+#    #+#             */
/*   Updated: 2021/04/27 20:23:18 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	ft_atoi(char *s)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (s[i])
		ret = (ret * 10) + (s[i++] - '0');
	return (ret);
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
	free(philo);
	exit(0);
}

int	ft_check_input(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6 )
	{
		printf("Invalid number of arguments.\n");
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if ((argv[i][j] > '9' || argv[i][j] < '0') || (argv[1][0]) == '0')
			{
				printf("Invalid arguments.\n");
				return (0);
			}
		}
	}
	return (1);
}
