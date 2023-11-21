/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:40:54 by jealves-          #+#    #+#             */
/*   Updated: 2023/11/21 21:40:35 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*program(void)
{
	static t_data	data;

	return (&data);
}

bool	ft_argv_isnumber(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	validate_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		msg_error("Error: Wrong number of arguments!");
		return (false);
	}
	if (!ft_argv_isnumber(argv))
	{
		msg_error("Error: Invalid arguments!");
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	if(!validate_args(argc, argv))
		return (1);
	init(argc, argv);
}
