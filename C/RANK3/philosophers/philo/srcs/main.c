/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:21:14 by llopes-d          #+#    #+#             */
/*   Updated: 2023/10/17 19:46:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// int	is_done(int philo_meals, t_data *data)
// {
// 	pthread_mutex_lock(&data->mutex_key);
// 	if (data->dead)
// 	{	
// 		pthread_mutex_unlock(&data->mutex_key);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&data->mutex_key);
// 	return (0);
// }

void *routine(void *args)
{
	t_philo	philo;

	philo = *(t_philo *)args;
	if (philo.id % 2 != 0)
			usleep(1000);
	while (1)
	{
		philo_eat(&philo);

		if (philo.meals == philo.data->arguments.must_eat || philo.data->dead)
		{	
			pthread_mutex_unlock(&philo.data->mutex_key);
			break;
		}

		philo_sleep(philo);
		pthread_mutex_lock(&philo.data->mutex_key);
		if (philo.meals == philo.data->arguments.must_eat || philo.data->dead)
		{	
			pthread_mutex_unlock(&philo.data->mutex_key);
			break;
		}
		pthread_mutex_unlock(&philo.data->mutex_key);

		philo_think(philo);
	}
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		number_of_philosophers;
	int		i;

	if ((argc != 5 && argc != 6) || is_arguments_invalid(argc, argv))
		return (printf("Error\n"));
	number_of_philosophers = init_variables(&data, argc, argv);
	if (!number_of_philosophers)
		return (printf("Error\n"));


	pthread_mutex_init(&data.mutex, NULL);
	pthread_mutex_init(&data.mutex_key, NULL);
	i = -1;
	while (++i < number_of_philosophers)
		pthread_create(&data.philo[i].philo_thread, NULL, routine, &data.philo[i]);



	i = 0;
	while (i < number_of_philosophers)
		pthread_join(data.philo[i++].philo_thread, NULL);

	i = 0;
	while (i < number_of_philosophers)
		pthread_mutex_destroy(&data.forks_mutex[i++]);

	pthread_mutex_destroy(&data.mutex);
	pthread_mutex_destroy(&data.mutex_key);
	return (0);
} 


