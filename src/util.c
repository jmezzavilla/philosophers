/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:14:55 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/26 23:35:35 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_strcmp(const char *s1, const char *s2)
{
	size_t	count;

	count = 0;
	while (s1[count] == s2[count] && s1[count] != '\0')
	{
		count++;
	}
	if (((unsigned char)s1[count] - (unsigned char)s2[count]) == 0)
		return (true);
	return (false);
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
	if (ft_atol(str) < 0)
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
