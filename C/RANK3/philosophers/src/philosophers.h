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
	int	last_time_eat;
	int	number_of_forks;
	t_args	args;
}	t_philosopher;

typedef struct s_fork
{
	int	is_on_table;
}	t_fork;

typedef struct s_data
{
	long long int	total_milliseconds;
	int	philo_initiated;
	t_philosopher	*philo;
	t_fork	*fork;
}	t_data;

int	ft_atoi(const char *str);

void	*ms_counter(void *total_milliseconds);


#endif