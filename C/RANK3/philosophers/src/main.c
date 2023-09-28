/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:07:23 by user              #+#    #+#             */
/*   Updated: 2023/09/28 17:52:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char *argv[])
{
	t_data	data;
	int		index;
	int		number_of_philosophers;

	if ((argc != 5 && argc != 6) || is_arguments_empty(argc, argv))
		return (0);
	index = 0;
	data.philo_initiated = 0;
	data.someone_died = 0;
	data.total_milliseconds = 0;
	data.philo = init_philos(argc, argv);
	number_of_philosophers = data.philo[0].args.number_of_philosophers;
	data.forks = init_forks(number_of_philosophers);
	pthread_mutex_init(&data.mutex, NULL);
	pthread_create(&data.ms_counter_t, NULL, ms_counter, &data);
	while (index < number_of_philosophers)
		pthread_create(&data.philo[index++].philo_t, NULL, manage_actions, &data);
	index = 0;
	while (index < number_of_philosophers)
		pthread_join(data.philo[index++].philo_t, NULL);
	pthread_join(data.ms_counter_t, NULL);
	pthread_mutex_destroy(&data.mutex);
	free(data.forks);
	free(data.philo);
	return (0);
}
