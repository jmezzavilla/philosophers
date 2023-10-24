/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:16:30 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/24 21:27:22 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg(char *str)
{
	printf("%s\n", str);
}

void	msg_error(char *str)
{
	msg(str);
	exit(EXIT_FAILURE);
}

void	messages(char *str, t_philo *philo)
{
	time_t	time;
	if (!check_death(philo) && !philo->data->is_dead)
	{
		pthread_mutex_lock(&philo->data->write);
		time = time_diff(philo);
		printf("%lu %ld %s\n", time, philo->id, str);
		pthread_mutex_unlock(&philo->data->write);
	}
}

void	messages_death(char *str, t_philo *philo)
{
	time_t	time;

	pthread_mutex_lock(&philo->data->death);
	time = time_diff(philo);
	printf("%lu %ld %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->death);
}