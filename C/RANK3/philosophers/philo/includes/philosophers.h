/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:41:51 by llopes-d          #+#    #+#             */
/*   Updated: 2023/10/31 18:43:19 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define THINKING 0
# define SLEEPING 1
# define EATING 2

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>

struct	s_data;

typedef struct s_args
{
	int	number_of_philosophers;
	int	time_to_sleep;
	int	time_to_die;
	int	time_to_eat;
	int	must_eat;
}	t_args;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		philo_t;
	long			last_sleep;
	long			last_eat;
	int				next_fork;
	int				own_fork;
	int				status;
	int				meals;
	int				id;
}	t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks_mutex;
	t_args			arguments;
	long			init_time;
	t_philo			*philo;
	pthread_mutex_t	mutex;
	int				dead;
}	t_data;

/*-------------UTILS----------------*/
void		print_action(t_data *data, t_philo philo, char *action);
int			number_len_no_zero(char *str);
int			is_positive_number(char *str);
long int	ft_atoi(const char *str);
long int	time_now(t_philo philo);
long int	get_time(void);
void		ft_wait(t_philo philo, long time);

/*-------------INIT----------------*/
int			init_variables(t_data *data, int argc, char *argv[]);
void		get_arguments(t_data *data, int argc, char *argv[]);
int			is_arguments_invalid(int argc, char *argv[]);
void		init_forks_mutex(t_data *data);
void		init_philos(t_data *data);

/*-------------ACTIONS----------------*/
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_eat(t_philo *philo);
void		philo_die(t_philo philo);
int			is_satisfied(t_philo philo);
int			someone_died(t_data *data);

#endif
