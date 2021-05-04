/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 20:23:03 by etaranti          #+#    #+#             */
/*   Updated: 2021/04/27 20:23:04 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

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
	sem_t	*forks;
	sem_t	*meals;
	sem_t	*death;
	int		nb_phi;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	long	t_start;
	int		max_meal;
	long	last_meal;
	int		meal_cnt;
	int		nbr;
	int		*alive;
}				t_philo;

long	ft_time(void);
void	ft_usleep(int length);
int		ft_atoi(char *str);
void	ft_init_and_start(t_philo *s, char **av, int alive);
int		ft_check_input(int argc, char **argv);

#endif
