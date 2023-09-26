/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:07:23 by user              #+#    #+#             */
/*   Updated: 2023/09/26 14:10:50 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t mutex;

int	is_arguments_empty(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	return (0);
}

t_args	get_args(int argc, char *argv[])
{
	t_args args;

	args.number_of_philosophers = ft_atoi(argv[1]);
	args.time_to_die = ft_atoi(argv[2]);
	args.time_to_eat = ft_atoi(argv[3]);
	args.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		args.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		args.has_last_argument++;
	}
	else
	{
		args.number_of_times_each_philosopher_must_eat = 0;
		args.has_last_argument = 0;
	}
	return (args);
}

t_fork *init_forks(int number_of_philosophers)
{
	int	index;
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork) * number_of_philosophers);
	if (!fork)
		exit(0);
	index = 0;
	while (index < number_of_philosophers)
	{
		fork[index].is_on_table = 1;
		fork[index].id = index + 1;
		index++;
	}
	return (fork);
}

t_philosopher *init_philos(int argc, char *argv[])
{
	int		index;
	int		number_of_philosophers;
	t_philosopher	*philo;

	number_of_philosophers = ft_atoi(argv[1]);
	index = 0;
	philo = (t_philosopher *)malloc(sizeof(t_philosopher) * number_of_philosophers);
	if (!philo)
		exit(0);
	while (index < number_of_philosophers)
	{
		philo[index].id = index + 1;
		philo[index].last_time_get_fork = 0;
		philo[index].number_of_forks = 0;
		philo[index].last_time_went_sleep = 0;
		philo[index].is_sleeping = 0;
		philo[index].args = get_args(argc, argv);
		index++;
	}
	return (philo);
}

void	*manage_philosophers(void *args)
{
	int	index;
	int	total_milliseconds;
	t_philosopher	*philo;
	t_data **data = (t_data **)&args;

	pthread_mutex_lock(&mutex);
	// printf("data %d\n", (*(data))->philo_initiated);
	philo = &(*(data))->philo[(*(data))->philo_initiated++];
	pthread_mutex_unlock(&mutex);
	if (philo->id != 1)
		printf("%lld %d is thinking\n", (*(data))->total_milliseconds, philo->id);
	while (1)
	{
		total_milliseconds = (*(data))->total_milliseconds;

		is_dead(philo, total_milliseconds);

		if (!wake_up(philo, total_milliseconds))
			continue;

		pthread_mutex_lock(&mutex);
		get_fork(philo, &(*(data))->forks, total_milliseconds);
		pthread_mutex_unlock(&mutex);

		pthread_mutex_lock(&mutex);
		get_sleep(philo, &(*(data))->forks, total_milliseconds);
		pthread_mutex_unlock(&mutex);

	}
	return (void *)0;
}

int main(int argc, char *argv[])
{
	t_data	data;
	pthread_t ms_counter_t;
	int	index;
	int THREADS = ft_atoi(argv[1]);

	if ((argc != 5 && argc != 6) || is_arguments_empty(argc, argv))
		return (0);

	index = 0;
	data.philo_initiated = 0;
	data.philo = init_philos(argc, argv);
	data.forks = init_forks(data.philo[0].args.number_of_philosophers);
	pthread_mutex_init(&mutex, NULL);
	pthread_create(&ms_counter_t, NULL, ms_counter, &data.total_milliseconds);
	usleep(20000);
	while (index < THREADS)
		pthread_create(&data.philo[index++].philo_t, NULL, manage_philosophers, &data);

	index = 0;
	while (index < THREADS)
		pthread_join(data.philo[index++].philo_t, NULL);
	pthread_join(ms_counter_t, NULL);
	pthread_mutex_destroy(&mutex);
	free(data.forks);
	free(data.philo);
	return (0);
}
