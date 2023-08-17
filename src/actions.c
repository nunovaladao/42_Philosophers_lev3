/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:07:57 by nsoares-          #+#    #+#             */
/*   Updated: 2023/08/17 12:26:45 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat_routine(t_philo *p)
{
	t_input_args *input_args;
	int l_fork;
	int r_fork;
	long time;

	input_args = p->args;
	l_fork = p->left_fork;
	r_fork = p->right_fork;
	pthread_mutex_lock(&(input_args->fork[l_fork])); // Trava os grafos para ninguém pegar
	pthread_mutex_lock(&(input_args->fork[r_fork]));
	time = diffe_time(curr_time(), input_args->time);
	print_eat_routine(p, time);
	pthread_mutex_lock(&input_args->check); // Bloqueia o mutex check para atualizar os dados compartilhados de forma segura
	p->philo_ate += 1;
	p->last_meal = curr_time();
	pthread_mutex_unlock(&input_args->check);
	usleep(p->args->time_eat * 1000);
	pthread_mutex_unlock(&(input_args->fork[l_fork]));
	pthread_mutex_unlock(&(input_args->fork[r_fork])); // Liberta os garfos
}

void	sleep_routine(t_input_args *input_args)
{
	long	time;

	time = diffe_time(curr_time(), input_args->time);
	print_sleep_routine(input_args, time);
	usleep(input_args->time_sleep * 1000);
}

void	thinking_routine(t_input_args *input_args)
{
	long	time;

	time = diffe_time(curr_time(), input_args->time);
	print_thinking_routine(input_args, time);
}

// monitoring
