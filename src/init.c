/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 22:22:03 by nsoares-          #+#    #+#             */
/*   Updated: 2023/08/30 22:21:20 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	diffe_time(int actual_time, int previous_time)
{
	return (actual_time - previous_time);
}

long	curr_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	init_philo(t_input_args *input_args)
{
	int	i;

	i = 0;
	input_args->p = malloc(input_args->nb_philos * sizeof(t_philo));
	while (i < input_args->nb_philos)
	{
		input_args->p[i].args = input_args;
		input_args->p[i].philo_id = i + 1;
		input_args->p[i].philo_ate = 0;
		input_args->p[i].done_eating = 0;
		pthread_mutex_init(&input_args->fork[i], NULL);
		if (input_args->nb_philos > 1 && i != (input_args->nb_philos - 1))
		{
			input_args->p[i].left_fork = i;
			input_args->p[i].right_fork = i + 1;
		}
		else if (input_args->nb_philos > 1 && i == (input_args->nb_philos - 1)) 
		{
			input_args->p[i].left_fork = 0;
			input_args->p[i].right_fork = i;
		}
		input_args->p[i].last_meal = curr_time();
		i++;
	}
}

void	init_arguments(t_input_args *input_args, char **av)
{
	input_args->nb_philos = ft_atoi(av[1]);
	input_args->time_die = ft_atoi(av[2]);
	input_args->time_eat = ft_atoi(av[3]);
	input_args->time_sleep = ft_atoi(av[4]);
	input_args->nb_time_must_eat = -1;
	if (av[5])
		input_args->nb_time_must_eat = ft_atoi(av[5]);
	input_args->almost_satisfied = 0;
	input_args->all_phi_ate = 0;
	input_args->phi_died = 0;
	pthread_mutex_init(&input_args->check, NULL);
	pthread_mutex_init(&input_args->check_died, NULL);
}
