/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 19:31:31 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/23 11:54:16 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_timestamp(void)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, NULL))
		return (0);
	return ((curr_time.tv_sec * 1000) + (curr_time.tv_usec / 1000));
}

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_timestamp();
	while ((get_timestamp() - start) < time)
		usleep(time / 10);
}