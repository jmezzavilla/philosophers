/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jealves- <jealves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 22:15:05 by jealves-          #+#    #+#             */
/*   Updated: 2023/10/21 19:45:29 by jealves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_validate_args(int argc, char **argv)
{
    if(argc < 5 || argc > 6)
        msg_error("Wrong number of arguments!");
    if(!ft_argv_isnumber(argv))
		msg_error("Arguments must be numbers");
}