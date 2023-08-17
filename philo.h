/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsoares- <nsoares-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 11:35:30 by nsoares-          #+#    #+#             */
/*   Updated: 2023/08/17 17:07:13 by nsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_input_args {
    int nb_philos;
    int time_eat;
    int time_sleep;
    int time_die;
    int nb_time_must_eat;
    int				all_phi_ate;
	int				phi_died;
    long int time;
    pthread_mutex_t	fork[250];
	pthread_mutex_t	check;
	pthread_mutex_t	check_died;
	//pthread_mutex_t	check_died_full;
	pthread_mutex_t	print;
    struct s_philo *p;
}                   t_input_args;

typedef struct s_philo {
    t_input_args    *args;
    pthread_t		thread;
	long int	last_meal;
	int				philo_id;
	int				philo_ate;
	int				left_fork;
	int				right_fork;
	int				done_eating;
}                   t_philo;


// utils
int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);
int valid_args(char **av);
void handle_error(void);
void free_program(t_input_args *input_args);

// init
void init_arguments(t_input_args *input_args, char **av);
void init_philo(t_input_args *input_args);
long curr_time(void);
long diffe_time(int actual_time, int previous_time);

// threads
void init_threads(t_input_args *input_args, t_philo *p);

// actions
void eat_routine(t_philo *p);
void sleep_routine(t_input_args *input_args);
void thinking_routine(t_input_args *input_args);

// prints
void print_eat_routine(t_philo *p, long time);
void print_sleep_routine(t_input_args *input_args, long time);
void print_thinking_routine(t_input_args *input_args, long time);

#endif