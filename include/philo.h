/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:15:37 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/24 21:54:23 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
#include <unistd.h>

typedef struct s_data
{
	int				eat_time;
	int				max_eat_philo;
	int				die_time;
	int				sleep_time;
	int				nbr_philos;
	bool			is_dead;
	time_t			start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	death;
}					t_data;

typedef struct s_philo
{
	pthread_t		thread;
	size_t			id;
	int			eat_count;
	bool			is_sleeping;
	bool			is_eating;
	bool			is_thinking;
	time_t			last_meal;
	pthread_mutex_t	lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}					t_philo;

long				ft_atol(char *nptr);
bool				ft_isdigit(int c);
bool				ft_isnumber(char *str);
bool				ft_argv_isnumber(char **argv);

void				msg(char *str);
void				msg_error(char *str);
void				init(int argc, char **argv, t_data *data);
void				init_philos(t_data *data, t_philo *philo);
size_t				get_timestamp(void);
void				*routine(void *arg);
void				create_threads(t_data *data, t_philo *philo);
void				clean(t_data *data, t_philo *philo);
void				messages(char *str, t_philo *philo);
void	messages_death(char *str, t_philo *philo);
time_t				time_diff(t_philo *philo);

void	waiting_time(size_t time);
bool 	check_death(t_philo *philo);
void drop_forks(t_philo *philo);
void take_forks(t_philo *philo);

#endif