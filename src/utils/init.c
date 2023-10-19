/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 23:00:22 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/19 23:48:06 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_philos(t_data *data, t_philosophers **philo)
{
	int i;
	
	i = 0;
	
	while(i < data->nbr_philos)
	{
		philo[i]->eat_count = 0;
		philo[i]->is_eating = false;
		philo[i]->is_sleeping = false;
		philo[i]->
	}
}

void init(int argc, const char **argv, t_data *data)
{
	data->nbr_philos = ft_atol(argv[1]);
	data->die_time = ft_atol(argv[2]);
	data->eat_time = ft_atol(argv[3]);
	data->sleep_time = ft_atol(argv[4]);
	if(argc > 5)
		data->max_eat_philo = ft_atol(argv[5]);
	else
		data->max_eat_philo = INT_MAX;
	
	pthread_mutex_init(data->write, NULL);	
}


