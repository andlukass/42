/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:34:58 by user              #+#    #+#             */
/*   Updated: 2023/09/28 21:05:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_args
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int	has_last_argument;
}	t_args;

typedef struct s_philosopher
{
	pthread_t	philo_t;
	t_args		args;
	int			id;
	int			last_time_get_fork;
	int			last_time_went_sleep;
	int			is_sleeping;
	int			is_dead;
	int			number_of_forks;
}	t_philosopher;

typedef struct s_fork
{
	int	is_on_table;
	int	id;
}	t_fork;

typedef struct s_data
{
	pthread_t		ms_counter_t;
	pthread_mutex_t	mutex;
	t_philosopher	*philo;
	t_fork			*forks;
	long long int	total_milliseconds;
	int				someone_died;
	int				philo_initiated;
}	t_data;

/*-------------UTILS----------------*/
int				ft_atoi(const char *str);

/*--------------TIME----------------*/
void			*ms_counter(void *total_milliseconds);

// /*---------------INIT----------------*/
int				init_variables(t_data *data, int argc, char *argv[]);
int				is_arguments_empty(int argc, char *argv[]);
t_args			get_args(int argc, char *argv[]);
t_fork			*init_forks(int number_of_philosophers);
t_philosopher	*init_philos(int argc, char *argv[]);

// /*-------------ACTIONS---------------*/
void			get_fork(t_philosopher *philo, t_fork **forks, long total_ms);
void			get_sleep(t_philosopher *philo, t_fork **forks, long total_ms);
void			is_dead(t_philosopher *philo, long total_ms);
int				wake_up(t_philosopher *philo, long total_ms);
void			*manage_actions(void *args);

#endif