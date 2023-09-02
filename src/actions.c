/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:07:57 by nsoares-          #+#    #+#             */
/*   Updated: 2023/09/02 09:20:48 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	eat_routine(t_philo *p)
{
	t_input_args	*input_args;
	int				l_fork;
	int				r_fork;
	long			time;

	input_args = p->args;
	l_fork = p->left_fork;
	r_fork = p->right_fork;
	pthread_mutex_lock(&(input_args->fork[l_fork]));
	pthread_mutex_lock(&(input_args->fork[r_fork]));
	time = diffe_time(curr_time(), input_args->time);
	print_eat_routine(p, time);
	pthread_mutex_lock(&input_args->check);
	p->philo_ate += 1;
	p->last_meal = curr_time();
	pthread_mutex_unlock(&input_args->check);
	usleep(p->args->time_eat * 1000);
	pthread_mutex_unlock(&(input_args->fork[l_fork]));
	pthread_mutex_unlock(&(input_args->fork[r_fork]));
}

void	sleep_routine(t_input_args *input_args, int p_id)
{
	long	time;

	time = diffe_time(curr_time(), input_args->time);
	print_sleep_routine(input_args, time, p_id);
	usleep(input_args->time_sleep * 1000);
}

void	thinking_routine(t_philo *p, t_input_args *input_args)
{
	long	time;

	time = diffe_time(curr_time(), input_args->time);
	print_thinking_routine(p, input_args, time);
}

void	dead_check(t_input_args *input_args)
{
	int	i;

	while (input_args->all_phi_ate == 0 && input_args->phi_died == 0)
	{
		i = -1;
		while (++i < input_args->nb_philos)
		{
			pthread_mutex_lock(&input_args->check);
			if (print_dead(input_args, i) == 1)
				return ;
			if (input_args->p[i].philo_ate == input_args->nb_time_must_eat 
				&& !input_args->p[i].done_eating)
			{
				input_args->almost_satisfied++;
				input_args->p[i].done_eating++;
			}
			if (input_args->almost_satisfied == input_args->nb_philos)
				input_args->all_phi_ate = 1;
			pthread_mutex_unlock(&input_args->check);
		}
	}
}
