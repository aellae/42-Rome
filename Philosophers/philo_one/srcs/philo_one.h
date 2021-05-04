/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:46:39 by etaranti          #+#    #+#             */
/*   Updated: 2021/04/27 16:46:41 by etaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

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
	pthread_mutex_t	fork;
	pthread_mutex_t	*state;
	pthread_mutex_t	*meals;
	pthread_mutex_t	*prev;
	int				nb_phi;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	long			t_start;
	int				max_meal;
	long			last_meal;
	int				meal_cnt;
	int				nbr;
}					t_philo;

void	ft_init_thread(t_philo *s);
void	ft_alone(t_philo *philo);
long	ft_time(void);
void	ft_usleep(int length);
int		ft_atoi(char *str);
void	ft_start_thread(t_philo *s);
int		ft_check_input(int argc, char **argv);

#endif
