/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:24:45 by etaranti          #+#    #+#             */
/*   Updated: 2021/04/28 11:24:47 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	ft_check_input(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6 )
	{
		write(2, "Invalid number of arguments.\n", 29);
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
				write(2, "Invalid arguments.\n", 18);
				return (0);
			}
		}
	}
	return (1);
}

t_philo	ft_init_philo(int argc, char **argv)
{
	t_philo	philo;

	philo.nb_phi = ft_atoi(argv[1]);
	philo.t_die = ft_atoi(argv[2]);
	philo.t_eat = ft_atoi(argv[3]);
	philo.t_sleep = ft_atoi(argv[4]);
	philo.max_meal = -1;
	if (argc == 6)
		philo.max_meal = ft_atoi(argv[5]);
	philo.t_start = ft_time();
	philo.last_meal = philo.t_start;
	philo.meal_cnt = 0;
	sem_unlink("forks");
	sem_unlink("state");
	philo.forks = sem_open("forks", O_CREAT, S_IRWXU, (philo.nb_phi / 2));
	philo.state = sem_open("state", O_CREAT, S_IRWXU, 0);
	return (philo);
}

int	main(int argc, char **argv)
{
	t_philo		philo;

	if (ft_check_input(argc, argv) == 0)
		return (1);
	philo = ft_init_philo(argc, argv);
	ft_start_thread(philo);
	sem_close(philo.forks);
	sem_close(philo.state);
	sem_unlink("forks");
	sem_unlink("state");
	return (0);
}
