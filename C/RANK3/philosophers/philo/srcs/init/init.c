/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:17:05 by llopes-d          #+#    #+#             */
/*   Updated: 2023/10/16 18:37:40 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

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

void	get_arguments(t_data *data, int argc, char *argv[])
{
	data->arguments.number_of_philosophers = ft_atoi(argv[1]);
	data->arguments.time_to_die = ft_atoi(argv[2]);
	data->arguments.time_to_eat = ft_atoi(argv[3]);
	data->arguments.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->arguments.must_eat = ft_atoi(argv[5]);
	else
		data->arguments.must_eat = 0;
}

void	init_philos(t_data *data)
{
	int	number_of_philosophers;
	int	i;

	i = 0;
	number_of_philosophers = data->arguments.number_of_philosophers;
	if (number_of_philosophers == 0)
		return ;
	data->philo = malloc(sizeof(t_philo) * number_of_philosophers);
	while (i < number_of_philosophers)
	{
		data->philo[i].id = i + 1;
		data->philo[i].last_eat = 0;
		data->philo[i].meals = 0;
		data->philo[i].data = data;
		data->philo[i].own_fork = &data->forks_mutex[data->philo[i].id - 1];
		if (data->philo[i].id == number_of_philosophers)
			data->philo[i].next_fork = &data->forks_mutex[0];
		else
			data->philo[i].next_fork = &data->forks_mutex[data->philo[i].id];
		printf("0\t%d is thinking\n", data->philo[i].id);
		i++;
	}
}

void	init_forks_mutex(t_data *data)
{
	int	num_of_philosophers;
	int	i;

	i = 0;
	num_of_philosophers = data->arguments.number_of_philosophers;
	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * num_of_philosophers);
	while (i < num_of_philosophers)
		pthread_mutex_init(&data->forks_mutex[i++], NULL);
}

int	init_variables(t_data *data, int argc, char *argv[])
{
	data->init_time = get_time();
	data->dead = 0;
	data->satisfied = 0;
	get_arguments(data, argc, argv);
	init_forks_mutex(data);
	init_philos(data);
	return (data->arguments.number_of_philosophers);
}
