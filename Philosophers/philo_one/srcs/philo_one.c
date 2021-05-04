/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:46:26 by etaranti          #+#    #+#             */
/*   Updated: 2021/04/27 16:46:30 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_philo	*ft_init_input(int argc, char **argv, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		pthread_mutex_init(&philo[i].fork, NULL);
		if (i != 0)
			philo[i].prev = &philo[i - 1].fork;
		philo[i].nb_phi = ft_atoi(argv[1]);
		philo[i].t_die = ft_atoi(argv[2]);
		philo[i].t_eat = ft_atoi(argv[3]);
		philo[i].t_sleep = ft_atoi(argv[4]);
		philo[i].t_start = ft_time();
		philo[i].max_meal = -1;
		if (argc == 6)
			philo[i].max_meal = ft_atoi(argv[5]);
		philo[i].last_meal = philo[i].t_start;
		philo[i].meal_cnt = 0;
		philo[i].nbr = i + 1;
		i++;
	}
	philo[0].prev = &philo[i - 1].fork;
	return (philo);
}

int	main(int argc, char **argv)
{
	t_philo	*p;

	if (ft_check_input(argc, argv) == 0)
		return (1);
	p = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!p)
		return (1);
	p = ft_init_input(argc, argv, p);
	if (p->nb_phi == 1)
		ft_alone(p);
	ft_start_thread(p);
	return (0);
}
