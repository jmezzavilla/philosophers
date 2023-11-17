/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:00:22 by jealves-          #+#    #+#             */
/*   Updated: 2023/11/17 22:47:04 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	program()->start = get_timestamp();
	while (i < program()->nbr_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, &philo_life, &philo[i]))
			msg_error("Error: pthread_create!");
		i++;
	}
	i = 0;
	while (i < program()->nbr_philos)
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
	eat->time = program()->eat_time;
	sleep->time = program()->sleep_time;
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
	philo = malloc(sizeof(t_philo) * program()->nbr_philos);
	if(!philo)
		msg_error("Error: malloc!");
	while (i < program()->nbr_philos)
	{
		philo[i].id = i + 1;
		philo[i].eat_count = 0;
		philo[i].last_meal = get_timestamp();
		philo[i].left_fork = i;
		philo[i].right_fork = philo[i].id % program()->nbr_philos;
		philo[i].state = init_state();
		i++;
	}
	create_threads(philo);
}

void	init_forks(void)
{
	int	i;

	i = 0;
	program()->forks = malloc(sizeof(t_fork) * program()->nbr_philos);
	if (!program()->forks)
		msg_error("Error: malloc!");
	while (i < program()->nbr_philos)
	{
		program()->forks[i].using = false;
		pthread_mutex_init(&program()->forks[i].rs, NULL);
		i++;
	}
}

void	init(int argc, char **argv)
{
	program()->nbr_philos = ft_atol(argv[1]);
	if (program()->nbr_philos == 1)
		program()->die_time = 10;
	else
		program()->die_time = ft_atol(argv[2]);
	program()->eat_time = ft_atol(argv[3]);
	program()->sleep_time = ft_atol(argv[4]);
	if (argc == 6)
		program()->max_eat_philo = ft_atol(argv[5]);
	else
		program()->max_eat_philo = -1;
	program()->is_dead = false;
	pthread_mutex_init(&program()->write, NULL);
	pthread_mutex_init(&program()->death, NULL);
	pthread_mutex_init(&program()->write_death, NULL);
	init_forks();
	init_philos();
}
