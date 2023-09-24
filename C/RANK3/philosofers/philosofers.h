#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H

# include <stdio.h>
# include <unistd.h> 
# include <sys/time.h>
# include <stdlib.h> 

typedef struct s_args
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int	has_last_argument;
} t_args;

typedef struct s_philosopher
{
	int	last_time_eat;

} t_philosopher;

typedef struct s_forks
{
	int id;
	int	philo;
} t_forks;

int	ft_atoi(const char *str);


#endif