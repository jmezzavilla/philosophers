/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:29:59 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/23 12:48:36 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	
	if(philo->id % 2 == 0)
		usleep(1000);
	
	printf("philo %ld\n", philo->id);
	while (1)
	{
		/*philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);*/
	}
	return (NULL);
}
