/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:40:54 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/24 11:44:30 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	validate_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		msg_error("Error: Wrong number of arguments!");
	if (!ft_argv_isnumber(argv))
		msg_error("Error: Arguments must be numbers");
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	*philos;

	validate_args(argc, argv);
	init(argc, argv, &data);
	philos = malloc(sizeof(t_philo) * data.nbr_philos);
	init_philos(&data, philos);
	create_threads(&data, philos);
}
