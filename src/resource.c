/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resource.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:37:37 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/24 21:54:31 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void drop_forks(t_philo *philo)
{	
	pthread_mutex_unlock(philo->right_fork);
	messages("has drop right fork", philo);
	pthread_mutex_unlock(philo->left_fork);
	messages("has drop left fork", philo);
}

void take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	messages("has taken right fork", philo);
	if(philo->right_fork == philo->left_fork)
	{
		messages("Thinking", philo);
		waiting_time(philo->data->die_time + 1);
		check_death(philo);
		exit(0);
	}
	pthread_mutex_lock(philo->left_fork);
	messages("has taken left fork", philo);
}

bool 	check_death(t_philo *philo)
{
	int time;
	time = get_timestamp() - philo->last_meal;
	if (time > philo->data->die_time && !philo->data->is_dead )
	{
		philo->data->is_dead = true;
		messages_death("died", philo);
		return (true);
	}
	return (false);
}

