/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:07:23 by user              #+#    #+#             */
/*   Updated: 2023/09/29 17:03:11 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	int		number_of_philosophers;
	int		i;
	t_data	data;

	if ((argc != 5 && argc != 6) || is_arguments_invalid(argc, argv))
		return (0);
	i = 0;
	number_of_philosophers = init_variables(&data, argc, argv);
	if (!data.philo || !data.forks || !number_of_philosophers)
		return (0);
	pthread_mutex_init(&data.mutex, NULL);
	pthread_create(&data.ms_counter_t, NULL, ms_counter, &data);
	while (i < number_of_philosophers)
		pthread_create(&data.philo[i++].philo_t, NULL, manage_actions, &data);
	i = 0;
	while (i < number_of_philosophers)
		pthread_join(data.philo[i++].philo_t, NULL);
	pthread_join(data.ms_counter_t, NULL);
	pthread_mutex_destroy(&data.mutex);
	free(data.forks);
	free(data.philo);
	return (0);
}
