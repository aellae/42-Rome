/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:22:57 by etaranti          #+#    #+#             */
/*   Updated: 2021/04/27 20:22:59 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int	main(int ac, char **av)
{
	t_philo	*philo;
	int		i;

	if (ft_check_input(ac, av) == 0)
		return (1);
	philo = malloc(sizeof(t_philo) * ft_atoi(av[1]));
	if (!philo)
		return (1);
	i = 0;
	sem_unlink("forks");
	sem_unlink("meals");
	sem_unlink("death");
	philo[0].forks = sem_open("forks", O_CREAT, S_IRWXU, (ft_atoi(av[1]) / 2));
	philo[0].meals = sem_open("meals", O_CREAT, S_IRWXU, 0);
	philo[0].death = sem_open("death", O_CREAT, S_IRWXU, 0);
	ft_init_and_start(philo, av, 1);
	sem_close(philo[0].death);
	sem_close(philo[0].forks);
	sem_close(philo[0].meals);
	sem_unlink("forks");
	sem_unlink("meals");
	sem_unlink("death");
	free(philo);
	return (0);
}
