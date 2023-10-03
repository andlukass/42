/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:42:17 by user              #+#    #+#             */
/*   Updated: 2023/10/03 20:07:55 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	is_arguments_invalid(int argc, char *argv[])
{
	int		index;
	long	arg_in_number;

	index = 1;
	while (index < argc)
	{
		if (!is_positive_number(argv[index]))
			return (1);
		if (number_len_no_zero(argv[index]) > 11)
			return (1);
		arg_in_number = ft_atoi(argv[index]);
		if (arg_in_number > 2147483647 || arg_in_number < -2147483648)
			return (1);
		index++;
	}
	return (0);
}

t_args	get_args(int argc, char *argv[])
{
	t_args	args;

	args.number_of_philosophers = ft_atoi(argv[1]);
	args.time_to_die = ft_atoi(argv[2]);
	args.time_to_eat = ft_atoi(argv[3]);
	args.time_to_sleep = ft_atoi(argv[4]);
	return (args);
}

t_fork	*init_forks(int number_of_philosophers)
{
	int		index;
	t_fork	*fork;

	fork = (t_fork *)malloc(sizeof(t_fork) * number_of_philosophers);
	if (!fork)
		return (NULL);
	index = 0;
	while (index < number_of_philosophers)
	{
		fork[index].is_on_table = 1;
		fork[index].id = index + 1;
		index++;
	}
	return (fork);
}

t_philosopher	*init_philos(int argc, char *argv[])
{
	int				index;
	int				number_of_philosophers;
	t_philosopher	*philo;

	number_of_philosophers = ft_atoi(argv[1]);
	index = 0;
	philo = (t_philosopher *)malloc(sizeof(t_philosopher) \
									* number_of_philosophers);
	if (!philo)
		return (NULL);
	while (index < number_of_philosophers)
	{
		philo[index].id = index + 1;
		philo[index].last_time_get_fork = 0;
		philo[index].number_of_forks = 0;
		philo[index].last_time_went_sleep = 0;
		philo[index].is_sleeping = 0;
		philo[index].is_dead = 0;
		philo[index].number_of_meals = 0;
		philo[index].args = get_args(argc, argv);
		index++;
	}
	return (philo);
}

int	init_variables(t_data *data, int argc, char *argv[])
{
	int	number_of_philosophers;

	data->total_milliseconds = 0;
	data->already_satisfied = 0;
	data->philo_initiated = 0;
	data->someone_died = 0;
	data->args = get_args(argc, argv);
	data->philo = init_philos(argc, argv);
	if (!data->philo)
		return (0);
	number_of_philosophers = data->philo[0].args.number_of_philosophers;
	data->forks = init_forks(number_of_philosophers);
	if (!data->forks)
		return (0);
	return (number_of_philosophers);
}
