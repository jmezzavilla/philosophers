/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:15:37 by jealves-          #+#    #+#             */
/*   Updated: 2023/11/17 21:56:23 by jealves-         ###   ########.fr       */
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
# include <unistd.h>

# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"
# define TAKEN_FORK "has taken fork"

typedef struct s_fork
{
	bool			using;
	pthread_mutex_t	rs;
}					t_fork;

typedef struct s_data
{
	int				eat_time;
	int				max_eat_philo;
	int				die_time;
	int				sleep_time;
	int				nbr_philos;
	bool			is_dead;
	time_t			start;
	t_fork			*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	death;
	pthread_mutex_t	write_death;
}					t_data;

typedef struct s_state
{
	char			*task;
	int				time;
	struct s_state	*next;
}					t_state;

typedef struct s_philo
{
	t_state			*state;
	pthread_t		thread;
	size_t			id;
	int				eat_count;
	time_t			last_meal;
	int				left_fork;
	int				right_fork;
}					t_philo;

t_data				*program(void);
long				ft_atol(char *nptr);
bool				ft_isdigit(int c);
bool				ft_isnumber(char *str);
bool				ft_strcmp(const char *s1, const char *s2);

void				msg_error(char *str);
void				write_msg(t_philo *philo, char *msg);

void				init(int argc, char **argv);

void				*philo_life(void *arg);

size_t				get_timestamp(void);
time_t				time_diff(void);
void				waiting_time(t_philo *philo);
bool				check_death(t_philo *philo);

void				clean(t_philo *philo);
void				clean_states_philo(t_philo *philo);

#endif
