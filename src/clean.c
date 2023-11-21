/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:47:02 by jealves-          #+#    #+#             */
/*   Updated: 2023/11/21 21:38:06 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_states_philo(t_philo *philo)
{
	int		i;
	t_state	*cur;

	i = 0;
	while (i < 3)
	{
		cur = philo->state->next;
		free(philo->state);
		philo->state = cur;
		i++;
	}
}

void	clean(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < program()->nbr_philos)
	{
		pthread_mutex_destroy(&program()->forks[i].rs);
		i++;
	}
	pthread_mutex_destroy(&program()->write);
	pthread_mutex_destroy(&program()->death);
	pthread_mutex_destroy(&program()->write_death);
	free(program()->forks);
	free(philo);
}

void	msg_error(char *str)
{
	printf("%s\n", str);
}

void	write_msg(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&program()->write);
	if (!check_death(philo))
		printf("%lu %ld %s\n", time_diff(), philo->id, msg);
	pthread_mutex_unlock(&program()->write);
	if (ft_strcmp(philo->state->task, msg))
		waiting_time(philo);
}
