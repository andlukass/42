#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H

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
	int	id;
	pthread_t	philo_t;
	int	last_time_get_fork;
	int	last_time_went_sleep;
	int	is_sleeping;
	int	is_dead;
	int	number_of_forks;
	t_args	args;
}	t_philosopher;

typedef struct s_fork
{
	int	is_on_table;
	int	id;
}	t_fork;

typedef struct s_data
{
	long long int	total_milliseconds;
	pthread_t	ms_counter_t;
	pthread_mutex_t	mutex;
	int	someone_died;
	int	philo_initiated;
	t_philosopher	*philo;
	t_fork	*forks;
}	t_data;

/*-------------UTILS----------------*/
int	ft_atoi(const char *str);

/*--------------TIME----------------*/
void	*ms_counter(void *total_milliseconds);

/*---------------INIT----------------*/
int	is_arguments_empty(int argc, char *argv[]);
t_args	get_args(int argc, char *argv[]);
t_fork *init_forks(int number_of_philosophers);
t_philosopher *init_philos(int argc, char *argv[]);

/*-------------ACTIONS---------------*/
void	get_fork(t_philosopher *philo, t_fork **forks, long long total_ms);
void	get_sleep(t_philosopher *philo, t_fork **forks, long long total_ms);
void	is_dead(t_philosopher *philo, long long total_ms);
int		wake_up(t_philosopher *philo, long long total_ms);
void	*manage_actions(void *args);

#endif