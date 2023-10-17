/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:15:37 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/17 20:01:30 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <pthread.h>

typedef struct s_philosophers
{
    pthread_t thread;
    size_t eat_count;
    bool is_sleeping;
    bool is_eating;
    uint64_t die;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *left_fork;
    t_program *program;
}   t_philosophers;

typedef struct s_program
{
    t_philosophers *philosophers;
    uint64_t eat;
    uint64_t die;
    uint64_t sleep;
    uint64_t start;
    pthread_mutex_t *fork;
} t_program;

long	ft_atol(const char *nptr);
int	ft_isdigit(int c);
int	ft_isnumber(char *str);

#endif