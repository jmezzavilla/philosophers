/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:31:31 by jealves-          #+#    #+#             */
/*   Updated: 2023/11/02 19:47:50 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_death(t_philo *philo)
{
	pthread_mutex_lock(&program()->death);
	if (program()->is_dead)
	{
		pthread_mutex_unlock(&program()->death);
		return (true);
	}
	if ((get_timestamp()
			- philo->last_meal) > (long unsigned int)program()->die_time)
	{
		program()->is_dead = true;
		write_msg(philo, DIED);
		pthread_mutex_unlock(&program()->death);
		return (true);
	}
	pthread_mutex_unlock(&program()->death);
	return (false);
}

size_t	get_timestamp(void)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, NULL))
		return (0);
	return ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));
}

void	waiting_time(t_philo *philo)
{
	size_t	start;

	start = get_timestamp();
	while ((get_timestamp() - start) < (long unsigned int)philo->state->time
		&& !check_death(philo))
		usleep(10);
}

time_t	time_diff(void)
{
	time_t	diff;

	diff = get_timestamp() - program()->start;
	return (diff);
}
