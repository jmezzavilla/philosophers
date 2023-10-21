/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:00:22 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/21 20:15:02 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_forks(t_data *data)
{
	int i;
	
	i = 0;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_philos);
	
	if(!data->forks)
		msg_error("Error malloc // alterar");
		
	while(i < data->nbr_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void init_philos(t_data *data, t_philo **philo)
{
	int i;
	
	i = 0;
	init_forks(data);
	philo = malloc(sizeof(t_philo *) * data->nbr_philos);

	while(i < data->nbr_philos)
	{
		//philo[i]->thread = malloc(sizeof(pthread_t) * 1);
		philo[i] = malloc(sizeof(t_philo) * 1);
		philo[i]->id = i;
		philo[i]->eat_count = 0;
		philo[i]->last_meal = 0;
		philo[i]->is_eating = false;
		philo[i]->is_sleeping = false;
		philo[i]->data = data;
		
		pthread_mutex_init(&philo[i]->lock, NULL);
		philo[i]->left_fork = &data->forks[i];
		if(i == 0)
			philo[i]->right_fork = &data->forks[data->nbr_philos - 1];
		else
			philo[i]->right_fork = &data->forks[i - 1];
		i++;
	}
}

void init(int argc, char **argv, t_data *data)
{
	data->nbr_philos = ft_atol(argv[1]);
	data->die_time = ft_atol(argv[2]);
	data->eat_time = ft_atol(argv[3]);
	data->sleep_time = ft_atol(argv[4]);
	if(argc > 5)
		data->max_eat_philo = ft_atol(argv[5]);
	else
		data->max_eat_philo = INT_MAX;
	
	pthread_mutex_init(&data->write, NULL);	
}
