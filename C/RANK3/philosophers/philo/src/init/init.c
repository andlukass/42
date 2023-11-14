/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:17:05 by llopes-d          #+#    #+#             */
/*   Updated: 2023/11/14 17:05:24 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	is_args_invalid(int argc, char *argv[])
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

void	get_args(t_data *data, int argc, char *argv[])
{
	data->args.number_of_philo = ft_atoi(argv[1]);
	data->args.time_to_die = ft_atoi(argv[2]);
	data->args.time_to_eat = ft_atoi(argv[3]);
	data->args.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->args.must_eat = ft_atoi(argv[5]);
	else
		data->args.must_eat = -1;
	if (ft_atoi(argv[1]) % 2 == 0)
		data->args.time_to_think = data->args.time_to_eat \
			- data->args.time_to_sleep;
	else
		data->args.time_to_think = data->args.time_to_eat;
}

void	init_philos(t_data *data)
{
	int	number_of_philo;
	int	i;

	i = 0;
	number_of_philo = data->args.number_of_philo;
	if (number_of_philo == 0)
		return ;
	data->philo = malloc(sizeof(t_philo) * number_of_philo);
	while (i < number_of_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].last_eat = 0;
		data->philo[i].last_sleep = 0;
		data->philo[i].last_think = 0;
		data->philo[i].meals = 0;
		data->philo[i].status = THINKING;
		data->philo[i].data = data;
		data->philo[i].own_fork = data->philo[i].id - 1;
		if (data->philo[i].id == data->args.number_of_philo)
			data->philo[i].next_fork = 0;
		else
			data->philo[i].next_fork = data->philo[i].id;
		i++;
	}
}

void	init_forks_mutex(t_data *data)
{
	int	num_of_philosophers;
	int	i;

	i = 0;
	num_of_philosophers = data->args.number_of_philo;
	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * num_of_philosophers);
	while (i < num_of_philosophers)
		pthread_mutex_init(&data->forks_mutex[i++], NULL);
}

int	init_variables(t_data *data, int argc, char *argv[])
{
	get_args(data, argc, argv);
	init_forks_mutex(data);
	init_philos(data);
	data->init_time = 0;
	data->init_time = time_now(data->philo[0]);
	data->dead = 0;
	return (data->args.number_of_philo);
}
