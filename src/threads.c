/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:15:05 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/28 18:09:03 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	data()->start = get_timestamp();
	while (i < data()->nbr_philos)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]))
			msg_error("Error: pthread_create!");
		i++;
	}
	i = 0;
	while (i < data()->nbr_philos)
	{
		if (pthread_join(philo[i].thread, NULL))
			msg_error("Error: pthread_join!");
		i++;
	}
	clean(philo);
}
