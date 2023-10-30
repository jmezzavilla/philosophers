/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:16:30 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/30 17:36:17 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg_error(char *str)
{
	printf("%s\n", str);
	exit(EXIT_FAILURE);
}

bool	check_death(t_philo *philo)
{
	pthread_mutex_lock(&data()->death);
	if (data()->is_dead)
	{
		pthread_mutex_unlock(&data()->death);
		return (true);
	}
	if ((get_timestamp()
			- philo->last_meal) > (long unsigned int)data()->die_time)
	{
		data()->is_dead = true;
		write_msg(philo, DIED);
		pthread_mutex_unlock(&data()->death);
		return (true);
	}
	pthread_mutex_unlock(&data()->death);
	return (false);
}

void	write_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&data()->write);
	printf("%lu %ld %s\n", time_diff(), philo->id, msg);
	pthread_mutex_unlock(&data()->write);
	if (ft_strcmp(philo->state->task, msg))
		waiting_time(philo);
}
