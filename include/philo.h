/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:15:37 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/15 21:02:43 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <limits.h>
#include <pthread.h>

typedef struct s_philosophers
{
    pthread_t thread;
}   t_philosophers;

typedef struct s_program
{
    t_philosophers *philosophers;
} t_program;

long	ft_atol(const char *nptr);
int	ft_isdigit(int c);
int	ft_isnumber(char *str);

#endif