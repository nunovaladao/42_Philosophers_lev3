/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:32:35 by nsoares-          #+#    #+#             */
/*   Updated: 2023/08/30 16:41:52 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_program(t_input_args *input_args)
{
	int	i;

	i = 0;
	while (i < input_args->nb_philos)
	{
		pthread_mutex_destroy(&(input_args->fork[i]));
		i++;
	}
	pthread_mutex_destroy(&(input_args->check));
	pthread_mutex_destroy(&(input_args->check_died));
	free(input_args->p);
}

int	valid_args(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ft_atoi(av[1]) == 0 || ft_atoi(av[1]) > 200)
		return (1);
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			if (ft_isdigit(av[i][j]) == 0)
				return (1);
	}
	i = 1;
	while (++i < 5)
		if (ft_atoi(av[i]) < 60)
			return (1);
	return (0);
}

void	handle_error(void)
{
	printf(BOLD RED SUB "\nArgument Error\n\n" RESET);
	printf(" - Put only numbers\n");
	printf(" - The args related to time have to be greater than 60\n");
	printf(" - The first arg (Nº of Philos) need to be between 0 and 200\n\n");
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	s;
	int	res;
	int	i;

	i = 0;
	res = 0;
	s = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			s *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res * s);
}
