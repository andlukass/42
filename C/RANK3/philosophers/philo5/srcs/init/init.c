/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:17:05 by llopes-d          #+#    #+#             */
/*   Updated: 2023/10/15 13:01:16 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void get_arguments(t_data *data, int argc, char *argv[])
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
void init_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->arguments.number_of_philosophers + 1);
	while (i < data->arguments.number_of_philosophers)
	{
		data->philo[i].id = i + 1;
		data->philo[i].last_eat = get_time();
		data->philo[i].last_sleep = 0;
		data->philo[i].meals = 0;
		data->philo[i].dead = 0;
		data->philo[i].data = data;
		i++;
	}
}

void init_forks_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * data->arguments.number_of_philosophers + 1);
	while (i < data->arguments.number_of_philosophers)
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