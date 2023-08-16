/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 18:34:17 by nsoares-          #+#    #+#             */
/*   Updated: 2023/08/14 12:06:26 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *philo_routine(void *philo)
{
    t_input_args *input_args;
    t_philo *p;

    p = (t_philo *)philo;
    input_args = p->args;
    while (1)
    {
        pthread_mutex_lock(&input_args->check_died);
        if (input_args->nb_philos > 1 && input_args->phi_died == 0 
            && input_args->all_phi_ate == 0 && !p->done_eating)
        {
            pthread_mutex_unlock(&input_args->check_died);
            eat_routine(p);
            sleep_routine(input_args, input_args->nb_philos);
            // thinking
        }
        else
        {
            pthread_mutex_unlock(&input_args->check_died);
            break ;
        }
    }
    return (NULL);
}

void init_threads(t_input_args *input_args, t_philo *p)
{
    int i;

    i = 0;
    p = input_args->p;
    input_args->time = curr_time();
    while (i < input_args->nb_philos)
    {
        pthread_create(&p[i].thread, NULL, &philo_routine, &p[i]);
        i++;
    }
}
