/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:46:46 by etaranti          #+#    #+#             */
/*   Updated: 2021/04/27 16:46:48 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	ft_message(long start, int philo, char *string)
{
	long	now;

	now = ft_time() - start;
	printf("%zu ** %d -> %s\n", now, philo, string);
}

void	*ft_check_meal(void *ptr)
{
	t_philo	*p;
	int		i;

	p = (t_philo *)ptr;
	i = 0;
	if (p->max_meal != 0)
		pthread_mutex_lock(p->meals);
	while (p->max_meal != 0 && i < p->nb_phi)
	{
		pthread_mutex_lock(p->meals);
		i++;
	}
	ft_message(p->t_start, 0, "Everyone has eaten enough !");
	pthread_mutex_unlock(p->state);
	return (NULL);
}

void	*ft_check_death(void *ptr)
{
	t_philo	*p;

	p = (t_philo *)ptr;
	while (1)
	{
		if (ft_time() - p->last_meal > p->t_die)
		{
			ft_message(p->t_start, p->nbr, "has died");
			pthread_mutex_unlock(p->state);
			return (NULL);
		}
		else if (p->max_meal != -1 && p->meal_cnt >= p->max_meal)
		{
			ft_usleep((float)p->nbr);
			pthread_mutex_unlock(p->meals);
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
	pthread_create(&tid, NULL, ft_check_death, p);
	if (p->nbr % 2 == 0)
		ft_usleep((float)p->t_eat * 0.9 + 1);
	while (p->max_meal == -1 || p->max_meal > p->meal_cnt)
	{
		pthread_mutex_lock(&p->fork);
		ft_message(p->t_start, p->nbr, "has taken a fork");
		pthread_mutex_lock(p->prev);
		ft_message(p->t_start, p->nbr, "has taken a fork");
		p->last_meal = ft_time();
		ft_message(p->t_start, p->nbr, "is eating");
		ft_usleep(p->t_eat);
		pthread_mutex_unlock(&p->fork);
		pthread_mutex_unlock(p->prev);
		p->meal_cnt++;
		ft_message(p->t_start, p->nbr, "is sleeping");
		ft_usleep(p->t_sleep);
		ft_message(p->t_start, p->nbr, "is thinking");
	}
	return (NULL);
}

void	ft_start_thread(t_philo *philo)
{
	pthread_mutex_t	state;
	pthread_mutex_t	meals;
	pthread_t		tid;
	int				i;

	pthread_mutex_init(&state, NULL);
	pthread_mutex_init(&meals, NULL);
	pthread_mutex_lock(&state);
	i = -1;
	while (++i < philo[0].nb_phi)
	{
		philo[i].state = &state;
		philo[i].meals = &meals;
		pthread_create(&tid, NULL, ft_action, &philo[i]);
	}
	if (philo[0].max_meal > -1)
		pthread_create(&tid, NULL, ft_check_meal, &philo[0]);
	pthread_mutex_lock(&state);
	i = -1;
	while (++i < philo[0].nb_phi)
		pthread_mutex_destroy(&philo[i].fork);
	pthread_mutex_destroy(&state);
	pthread_mutex_destroy(&meals);
	free(philo);
}
