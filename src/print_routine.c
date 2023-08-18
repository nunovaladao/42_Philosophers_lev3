/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:38:59 by nsoares-          #+#    #+#             */
/*   Updated: 2023/08/18 13:50:10 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_eat_routine(t_philo *p, long time)
{
	pthread_mutex_lock(&p->args->check_died);
	if (p->args->phi_died == 0 && p->args->all_phi_ate == 0)
	{
		printf("Time: %ld | philo nº %d ", time, p->philo_id);
		printf("has taken a fork 🍴\n");
		printf("Time: %ld | philo nº %d ", time, p->philo_id);
		printf("has taken a fork 🍴\n");
		printf("Time: %ld | philo nº %d is eating 🍜\n", time, p->philo_id);
		pthread_mutex_unlock(&p->args->check_died);
	}
	else
	{
		pthread_mutex_unlock(&p->args->check_died);
		return ;
	}
}

void	print_sleep_routine(t_input_args *input_args, long time)
{
	pthread_mutex_lock(&input_args->check);

	if (input_args->all_phi_ate == 0 && input_args->phi_died == 0)
	{
		pthread_mutex_lock(&input_args->check_died);
		if (input_args->phi_died == 0)
			printf("Time: %ld | Philo nº %d is sleeping 😴\n", time, input_args->p->philo_id);
		pthread_mutex_unlock(&input_args->check_died);
	}
	pthread_mutex_unlock(&input_args->check);
}

void	print_thinking_routine(t_input_args *input_args, long time)
{
	pthread_mutex_lock(&input_args->check);

	if (input_args->all_phi_ate == 0 && input_args->phi_died == 0)
	{
		pthread_mutex_lock(&input_args->check_died);
		if (input_args->phi_died == 0)
			printf("Time: %ld | Philo nº %d is thinking 🤔\n", time, input_args->p->philo_id);
		pthread_mutex_unlock(&input_args->check_died);
	}
	pthread_mutex_unlock(&input_args->check);
}

int print_dead(t_input_args *input_args, int i)
{
	long time;

	time = diffe_time(curr_time(), input_args->time);
	if (diffe_time(curr_time(), input_args->p[i].last_meal) > input_args->time_die)
	{
		pthread_mutex_lock(&input_args->check_died);
		input_args->phi_died = 1;
		pthread_mutex_unlock(&input_args->check_died);
    	if (input_args->phi_died == 1)
        	printf("Time: %ld | Philo nº %d dead 💀\n", time, input_args->p->philo_id);
		pthread_mutex_unlock(&input_args->check);
		return (1);
	}
	return (0);
}
