#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

struct s_data;

typedef struct s_args
{
	int	number_of_philosophers;
	int	time_to_sleep;
	int	time_to_die;
	int	time_to_eat;
	int	must_eat;
} t_args;

typedef struct s_philo
{
	pthread_t		philo_thread;
	pthread_mutex_t	*next_fork;
	pthread_mutex_t	*own_fork;
	long			last_eat;
	int				meals;
	int				id;
	struct s_data	*data;
} t_philo;

typedef struct s_forks
{
	int	is_on_table;
	int	id;
} t_forks;

typedef struct s_data
{
	long			init_time;
	t_args			arguments;
	t_philo			*philo;
	pthread_mutex_t	*forks_mutex;
	int				dead;
	int				satisfied;
	pthread_mutex_t	mutex;
	pthread_mutex_t	mutex_key;
} t_data;


/*-------------UTILS----------------*/
int				number_len_no_zero(char *str);
int				is_positive_number(char *str);
long int		ft_atoi(const char *str);
long int		get_time(void);

/*-------------INIT----------------*/
int				init_variables(t_data *data, int argc, char *argv[]);
void			get_arguments(t_data *data, int argc, char *argv[]);
int				is_arguments_invalid(int argc, char *argv[]);
void			init_forks_mutex(t_data *data);
void			init_philos(t_data *data);

/*-------------ACTIONS----------------*/
void			philo_sleep(t_philo philo);
void			philo_think(t_philo philo);
void			philo_eat(t_philo *philo);


#endif