/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:15:37 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/21 22:13:47 by jealves-         ###   ########.fr       */
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

typedef struct s_data
{
	int				eat_time;
	int				max_eat_philo;
	int				die_time;
	int				sleep_time;
	int				nbr_philos;
	time_t			start;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	death;
}					t_data;

typedef struct s_philo
{
	pthread_t		thread;
	size_t			id;
	size_t			eat_count;
	bool			is_sleeping;
	bool			is_eating;
	time_t			last_meal;
	pthread_mutex_t	lock;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
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

#endif