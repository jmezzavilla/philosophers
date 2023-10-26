/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:47:02 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/26 23:35:04 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_states_philo(t_philo *philo)
{
	int		j;
	t_state	*cur;

	j = 0;
	while (j < 3)
	{
		cur = philo->state->next;
		free(philo->state);
		philo->state = cur;
		j++;
	}
}

void	clean(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data()->nbr_philos)
	{
		pthread_mutex_destroy(&data()->forks[i]->rs);
		i++;
	}
	pthread_mutex_destroy(&data()->write);
	pthread_mutex_destroy(&data()->death);
	free(data()->forks);
	free(philo);
}
