/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:07:23 by user              #+#    #+#             */
/*   Updated: 2023/09/24 18:34:41 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

int *init_forks(int number_of_philosophers)
{
	int	index;
	int	*fork;

	fork = (int *)malloc(sizeof(int) * number_of_philosophers);
	index = 0;
	while (index < number_of_philosophers)
	{
		fork[index] = index + 1;
		index++;
	}
	return (fork);
}

t_philosopher *init_philos(t_args args)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)malloc(sizeof(t_philosopher) * args.number_of_philosophers);
	return (philo);
}

int main(int argc, char *argv[])
{
	pthread_t ms_counter_t;
	long long int	total_milliseconds;
	t_philosopher	*philo;
	t_args	args;
	int	*fork;

	if ((argc != 5 && argc != 6) || is_arguments_empty(argc, argv))
		return (0);
	
	args = get_args(argc, argv);
	philo = init_philos(args);
	fork = init_forks(args.number_of_philosophers);

	pthread_create(&ms_counter_t, NULL, ms_counter, &total_milliseconds);





	pthread_join(ms_counter_t, NULL);
	free(fork);
	free(philo);
	return (0);
}
