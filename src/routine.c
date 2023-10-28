/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:29:59 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/28 18:00:49 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	drop_fork(t_fork *fork, t_philo *philo)
{
	while (!check_death(philo))
	{
		pthread_mutex_lock(&fork->rs);
		if (fork->using)
		{
			fork->using = false;
			pthread_mutex_unlock(&fork->rs);
			break ;
		}
		pthread_mutex_unlock(&fork->rs);
	}
}

void	take_fork(t_fork *fork, t_philo *philo)
{
	while (!check_death(philo))
	{
		pthread_mutex_lock(&fork->rs);
		if (!fork->using)
		{
			fork->using = true;
			pthread_mutex_unlock(&fork->rs);
			write_msg(philo, TAKEN_FORK);
			break ;
		}
		pthread_mutex_unlock(&fork->rs);
	}
}

void	philo_eat(t_philo *philo)
{
	if (philo->id % 2)
	{
		take_fork(&data()->forks[philo->left_fork], philo);
		take_fork(&data()->forks[philo->right_fork], philo);
	}
	else
	{
		take_fork(&data()->forks[philo->right_fork], philo);
		take_fork(&data()->forks[philo->left_fork], philo);
	}
	if (check_death(philo))
		return ;
	philo->last_meal = get_timestamp();
	philo->eat_count--;
	write_msg(philo, philo->state->task);
	drop_fork(&data()->forks[philo->right_fork], philo);
	drop_fork(&data()->forks[philo->left_fork], philo);
}

void	philo_life(t_philo *philo)
{
	if(!check_death(philo)){
		if (ft_strcmp(philo->state->task, EAT) && !check_death(philo))
			philo_eat(philo);
		else if (ft_strcmp(philo->state->task, SLEEP) && !check_death(philo))
			write_msg(philo, philo->state->task);
		else if (ft_strcmp(philo->state->task, THINK) && !check_death(philo))
			write_msg(philo, philo->state->task);
		philo->state = philo->state->next;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->eat_count && !check_death(philo))
	{
		philo_life(philo);
	}
	clean_states_philo(philo);
	return (NULL);
}
