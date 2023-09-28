/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:42:17 by user              #+#    #+#             */
/*   Updated: 2023/09/28 17:45:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

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
		philo[index].is_dead = 0;
		philo[index].args = get_args(argc, argv);
		index++;
	}
	return (philo);
}
