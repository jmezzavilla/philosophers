/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:00:22 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/28 17:45:54 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_state	*init_state(void)
{
	t_state	*think;
	t_state	*sleep;
	t_state	*eat;

	think = malloc(sizeof(t_state));
	sleep = malloc(sizeof(t_state));
	eat = malloc(sizeof(t_state));
	think->task = THINK;
	think->time = 0;
	eat->task = EAT;
	eat->time = data()->eat_time;
	sleep->task = SLEEP;
	sleep->time = data()->sleep_time;
	think->next = eat;
	eat->next = sleep;
	sleep->next = think;
	return (think);
}

void	init_forks(void)
{
	int	i;

	i = 0;
	data()->forks =  malloc(sizeof(t_fork) * data()->nbr_philos);
	if (!data()->forks)
		msg_error("Error: malloc // alterar");
	while (i < data()->nbr_philos)
	{
		data()->forks[i].using = false;
		pthread_mutex_init(&data()->forks[i].rs, NULL);
		i++;
	}
}

void	init_philos(t_philo *philo)
{
	int	i;

	i = 0;

	while (i < data()->nbr_philos)
	{
		philo[i].id = i + 1;
		philo[i].eat_count = data()->max_eat_philo;
		philo[i].last_meal = get_timestamp();
		philo[i].state = init_state();
		philo[i].left_fork = i;
		philo[i].right_fork = philo[i].id % data()->nbr_philos;
		i++;
	}
}

void	init(int argc, char **argv)
{
	data()->nbr_philos = ft_atol(argv[1]);
	data()->die_time = ft_atol(argv[2]);
	data()->eat_time = ft_atol(argv[3]);
	data()->sleep_time = ft_atol(argv[4]);
	if (argc == 6)
		data()->max_eat_philo = ft_atol(argv[5]);
	else
		data()->max_eat_philo = INT_MAX;
	data()->is_dead = false;
	init_forks();
	pthread_mutex_init(&data()->write, NULL);
	pthread_mutex_init(&data()->death, NULL);
}
