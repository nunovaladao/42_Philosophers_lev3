/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:35:30 by nsoares-          #+#    #+#             */
/*   Updated: 2023/08/31 16:40:37 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BOLD "\033[1m"
# define SUB "\033[4m"
# define RESET "\033[0m"

typedef struct s_input_args {
	int				nb_philos;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				nb_time_must_eat;
	int				all_phi_ate;
	int				phi_died;
	int				almost_satisfied;
	long int		time;
	pthread_mutex_t	fork[250];
	pthread_mutex_t	check;
	pthread_mutex_t	check_died;
	struct s_philo	*p;
}			t_input_args;

typedef struct s_philo {
	t_input_args	*args;
	pthread_t		thread;
	long int		last_meal;
	int				philo_id;
	int				philo_ate;
	int				left_fork;
	int				right_fork;
	int				done_eating;
}			t_philo;

// utils
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
int		valid_args(char **av);
void	handle_error(void);
void	free_program(t_input_args *input_args);

// init
void	init_arguments(t_input_args *input_args, char **av);
void	init_philo(t_input_args *input_args);
long	curr_time(void);
long	diffe_time(int actual_time, int previous_time);

// threads
void	init_threads(t_input_args *input_args, t_philo *p);

// actions
void	eat_routine(t_philo *p);
void	sleep_routine(t_input_args *input_args, int philo_id);
void	thinking_routine(t_philo *p, t_input_args *input_args);
void	dead_check(t_input_args *input_args);

// prints
void	print_eat_routine(t_philo *p, long time);
void	print_sleep_routine(t_input_args *input_args, long time, int p_id);
void	print_thinking_routine(t_philo *p, t_input_args *input_args, long time);
int		print_dead(t_input_args *input_args, int i);

#endif
