/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:25:03 by etaranti          #+#    #+#             */
/*   Updated: 2021/04/28 11:25:08 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	ft_message(long start, int philo, char *string)
{
	long	now;

	now = ft_time() - start;
	printf("%zu ** %d -> %s\n", now, philo, string);
}

void	*ft_check_meal(void *ptr)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)ptr;
	i = 0;
	while (i < philo->nb_phi)
	{
		sem_wait(philo->state);
		i++;
	}
	i = 0;
	ft_message(philo->t_start, 0, "Everyone has eaten enough !");
	while (i < philo->nb_phi)
		kill(philo->pid[i++], SIGTERM);
	free(philo->pid);
	sem_unlink("forks");
	sem_unlink("state");
	exit(0);
	return (NULL);
}

void	*ft_check_death(void *ptr)
{
	t_philo	*philo;
	int		check;

	philo = (t_philo *)ptr;
	check = 1;
	while (1)
	{
		if (ft_time() - philo->last_meal > philo->t_die)
		{
			ft_message(philo->t_start, philo->nbr, "has died");
			exit(0);
		}
		else if (philo->max_meal != -1 && \
			philo->meal_cnt >= philo->max_meal && check)
		{
			sem_post(philo->state);
			check = 0;
			return (NULL);
		}
	}
	return (NULL);
}

void	ft_action(t_philo philo)
{
	pthread_t	tid;

	pthread_create(&tid, NULL, ft_check_death, &philo);
	while (1)
	{
		if (!(philo.max_meal > -1 && philo.meal_cnt >= philo.max_meal))
		{
			sem_wait(philo.forks);
			ft_message(philo.t_start, philo.nbr, "has taken a fork");
			ft_message(philo.t_start, philo.nbr, "has taken a fork");
			philo.last_meal = ft_time();
			if (!(philo.max_meal > -1 && philo.meal_cnt >= philo.max_meal))
				ft_message(philo.t_start, philo.nbr, "is eating");
			ft_usleep(philo.t_eat);
			philo.meal_cnt++;
			sem_post(philo.forks);
			ft_message(philo.t_start, philo.nbr, "is sleeping");
			ft_usleep(philo.t_sleep);
			ft_message(philo.t_start, philo.nbr, "is thinking");
		}
	}
}

void	ft_start_thread(t_philo philo)
{
	int			i;
	pthread_t	tid;

	i = 0;
	philo.pid = malloc(sizeof(pid_t) * philo.nb_phi);
	if (!(philo.pid))
		return ;
	while (i < philo.nb_phi)
	{
		philo.pid[i] = fork();
		if (philo.pid[i] == 0)
		{
			philo.nbr = i + 1;
			ft_action(philo);
			i = philo.nb_phi;
		}
		i++;
	}
	if (philo.max_meal > -1)
		pthread_create(&tid, NULL, ft_check_meal, &philo);
	waitpid(-1, NULL, 0);
	i = 0;
	while (i < philo.nb_phi)
		kill(philo.pid[i++], SIGTERM);
	free(philo.pid);
}
