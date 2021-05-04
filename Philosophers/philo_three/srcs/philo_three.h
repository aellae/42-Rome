/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:24:49 by etaranti          #+#    #+#             */
/*   Updated: 2021/04/28 11:24:51 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/time.h>

typedef struct s_philo
{
	pid_t	*pid;
	sem_t	*forks;
	sem_t	*state;
	int		nb_phi;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	long	t_start;
	int		max_meal;
	long	last_meal;
	int		meal_cnt;
	int		nbr;
}				t_philo;

long	ft_time(void);
void	ft_usleep(int length);
int		ft_atoi(char *str);
t_philo	ft_init_philo(int argc, char **argv);
void	ft_alone(t_philo *philo);
void	ft_start_thread(t_philo philo);

#endif
