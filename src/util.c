/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:14:55 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/24 11:45:28 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

bool	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

bool	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	if (ft_atol(str) > INT_MAX)
		return (false);
	if (ft_atol(str) < INT_MIN)
		return (false);
	return (true);
}

long	ft_result_atol(char *nptr, int sign, int i)
{
	long	result;

	result = 0;
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		if ((result > LONG_MAX / 10) || (result == LONG_MAX / 10 && (nptr[i]
					- '0') > (LONG_MAX % 10)))
		{
			if (sign == -1)
				return (LONG_MIN);
			else
				return (LONG_MAX);
		}
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

long	ft_atol(char *nptr)
{
	long	i;
	long	sign;

	i = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	return (ft_result_atol(nptr, sign, i));
}
