/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:15:37 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/19 23:45:58 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_philosophers
{
	pthread_t		thread;
	size_t			eat_count;
	bool			is_sleeping;
	bool			is_eating;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_data		*data;
}					t_philosophers;

typedef struct s_data
{
	int				eat_time;
	int				max_eat_philo;
	int				die_time;
	int				sleep_time;
	int				nbr_philos;
	uint64_t		start;
	pthread_mutex_t	*write;
}					t_data;

long				ft_atol(const char *nptr);
bool				ft_isdigit(int c);
bool				ft_isnumber(char *str);
bool				ft_argv_isnumber(const char **argv);
void				ft_validate_args(int argc, char const **argv);

void				msg(char *str);
void				msg_error(char *str);
void init(int argc, const char **argv, t_data *data);
void init_philos(t_data *data, t_philosophers **philo);

#endif