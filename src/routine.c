/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:29:59 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/24 21:54:51 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	take_forks(philo);
	philo->last_meal = get_timestamp();
	messages("is eating", philo);
	philo->is_thinking = false;
	philo->is_eating = true;
	philo->eat_count++;
	waiting_time(philo->data->eat_time);
	drop_forks(philo);
}

void	philo_sleep(t_philo *philo)
{
	messages("is sleeping", philo);
	philo->is_eating = false;
	philo->is_sleeping = true;
	waiting_time(philo->data->sleep_time);
}
void	philo_think(t_philo *philo)
{
	philo->is_sleeping = false;
	philo->is_thinking = true;
	messages("is thinking", philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		messages("is thinking", philo);
		waiting_time(philo->data->eat_time);
	}
	
	while (!philo->data->is_dead && philo->eat_count < philo->data->max_eat_philo)
	{
		if(philo->is_thinking)
			philo_eat(philo);
		else if(philo->is_eating)
			philo_sleep(philo);
		else if(philo->is_sleeping)
			philo_think(philo);
	}	
	return (NULL);
}
