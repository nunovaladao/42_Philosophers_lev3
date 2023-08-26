/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:26:24 by nsoares-          #+#    #+#             */
/*   Updated: 2023/08/26 15:16:12 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void one_philo()
{
	printf("Time: 0 | philo nº 1 has taken a fork 🍴\n");
}

int	main(int ac, char **av)
{
	t_input_args	input_args;
   	t_philo	p;

	if ((ac == 5 || ac == 6) && valid_args(av) == 0)
	{
        init_arguments(&input_args, av);
		init_philo(&input_args);
		printf("Philosophers Program Begin\n\n");
		if (input_args.nb_philos == 1)
			one_philo();
		init_threads(&input_args, &p);
		if (input_args.all_phi_ate == 1)
			printf("All philos ate! 🤤\n");
		free_program(&input_args);
	}
	else
		handle_error();
    //free_program(&input_args);
}
