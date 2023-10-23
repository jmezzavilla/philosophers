/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:29:59 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/23 16:43:10 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(&philo->lock);
	philo->is_eating = true;
	messages("To comendo",philo);
	philo->eat_count++;
	ft_usleep(philo->data->eat_time);
	philo->is_eating = false;
	pthread_mutex_unlock(&philo->lock);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

void philo_sleep(t_philo *philo)
{
	messages("Vou dormir", philo);
	ft_usleep(philo->data->sleep_time);
}
void philo_think(t_philo *philo)
{
	messages("to pensando enquanto espero", philo);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	
	if(philo->id % 2 == 0)
		usleep(1000);
	
	while (!philo->is_dead)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
