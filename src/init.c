/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:00:22 by jealves-          #+#    #+#             */
/*   Updated: 2023/11/01 18:50:35 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	data()->start = get_timestamp();
	while (i < data()->nbr_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, &philo_life, &philo[i]))
			msg_error("Error: pthread_create!");
		i++;
	}
	i = 0;
	while (i < data()->nbr_philos)
	{
		if (pthread_join(philo[i].thread, NULL))
			msg_error("Error: pthread_join!");
		i++;
	}
	clean(philo);
}

t_state	*init_state(void)
{
	t_state	*think;
	t_state	*sleep;
	t_state	*eat;

	think = malloc(sizeof(t_state));
	sleep = malloc(sizeof(t_state));
	eat = malloc(sizeof(t_state));
	think->task = THINK;
	eat->task = EAT;
	sleep->task = SLEEP;
	think->time = 0;
	eat->time = data()->eat_time;
	sleep->time = data()->sleep_time;
	think->next = eat;
	eat->next = sleep;
	sleep->next = think;
	return (think);
}

void	init_philos(void)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data()->nbr_philos);
	while (i < data()->nbr_philos)
	{
		philo[i].id = i + 1;
		philo[i].eat_count = data()->max_eat_philo;
		philo[i].last_meal = 0;
		philo[i].left_fork = i;
		philo[i].right_fork = philo[i].id % data()->nbr_philos;
		philo[i].state = init_state();
		i++;
	}
	create_threads(philo);
}

void	init_forks(void)
{
	int	i;

	i = 0;
	data()->forks = malloc(sizeof(t_fork) * data()->nbr_philos);
	if (!data()->forks)
		msg_error("Error: malloc!");
	while (i < data()->nbr_philos)
	{
		data()->forks[i].using = false;
		pthread_mutex_init(&data()->forks[i].rs, NULL);
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
	pthread_mutex_init(&data()->write, NULL);
	pthread_mutex_init(&data()->death, NULL);
	init_forks();
	init_philos();
}
