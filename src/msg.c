/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:16:30 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/23 16:26:14 by jealves-         ###   ########.fr       */
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

	pthread_mutex_lock(&philo->data->write);
	time = get_timestamp() - philo->data->start;
	printf("%lu %ld %s\n", time, philo->id, str);
	pthread_mutex_unlock(&philo->data->write);
}
