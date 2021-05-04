/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:23:08 by etaranti          #+#    #+#             */
/*   Updated: 2021/04/27 20:23:10 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

void	ft_message(int alive, long start, int philo, char *string)
{
	long	now;

	if (!alive)
		return ;
	now = ft_time() - start;
	printf("%zu ** %d -> %s\n", now, philo, string);
}

void	*ft_check_meal(void *ptr)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)ptr;
	i = 0;
	while (philo->max_meal != 0 && i < philo->nb_phi)
	{
		sem_wait(philo->meals);
		i++;
	}
	*philo->alive = 0;
	ft_message(1, philo->t_start, 0, "Everyone has eaten enough !");
	sem_post(philo->death);
	return (NULL);
}

void	*ft_check_death(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	while (*philo->alive)
	{
		if (ft_time() - philo->last_meal > philo->t_die)
		{
			*philo->alive = 0;
			ft_message(1, philo->t_start, philo->nbr, "has died");
			sem_post(philo->death);
			return (NULL);
		}
		else if (philo->max_meal != -1 && philo->meal_cnt >= philo->max_meal)
		{
			ft_usleep(philo->nbr);
			sem_post(philo->meals);
			return (NULL);
		}
	}
	return (NULL);
}

void	*ft_action(void *ptr)
{
	pthread_t	tid;
	t_philo		*p;

	p = (t_philo *)ptr;
	p->last_meal = p->t_start;
	p->meal_cnt = 0;
	pthread_create(&tid, NULL, ft_check_death, p);
	while (*p->alive && (p->max_meal == -1 || p->max_meal > p->meal_cnt))
	{
		sem_wait(p->forks);
		ft_message(*p->alive, p->t_start, p->nbr, "has taken a fork");
		ft_message(*p->alive, p->t_start, p->nbr, "has taken a fork");
		p->last_meal = ft_time();
		ft_message(*p->alive, p->t_start, p->nbr, "is eating");
		ft_usleep(p->t_eat);
		p->meal_cnt++;
		sem_post(p->forks);
		ft_message(*p->alive, p->t_start, p->nbr, "is sleeping");
		ft_usleep(p->t_sleep);
		ft_message(*p->alive, p->t_start, p->nbr, "is thinking");
	}
	return (NULL);
}

void	ft_init_and_start(t_philo *philo, char **av, int alive)
{
	int			i;
	pthread_t	tid;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		philo[i].forks = philo[0].forks;
		philo[i].meals = philo[0].meals;
		philo[i].death = philo[0].death;
		philo[i].nb_phi = ft_atoi(av[1]);
		philo[i].t_die = ft_atoi(av[2]);
		philo[i].t_eat = ft_atoi(av[3]);
		philo[i].t_sleep = ft_atoi(av[4]);
		philo[i].t_start = ft_time();
		philo[i].max_meal = -1;
		if (av[5])
			philo[i].max_meal = ft_atoi(av[5]);
		philo[i].nbr = i + 1;
		philo[i].alive = &alive;
		pthread_create(&tid, NULL, ft_action, &philo[i]);
	}
	if (philo[0].max_meal > -1)
		pthread_create(&tid, NULL, ft_check_meal, &philo[0]);
	sem_wait(philo[0].death);
	ft_usleep(philo[0].t_eat + philo[0].t_sleep);
}
