/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:21:14 by llopes-d          #+#    #+#             */
/*   Updated: 2023/10/18 08:27:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

static int	is_done(t_philo philo)
{
	pthread_mutex_lock(&philo.data->mutex_key);
	if (philo.meals == philo.data->arguments.must_eat || philo.data->dead)
	{
		// printf("philo: %d, encerrou2\n", philo.id);
		if (philo.is_eating == 1)
		{
			pthread_mutex_unlock(philo.next_fork);
			pthread_mutex_unlock(philo.own_fork);
		}
		pthread_mutex_unlock(&philo.data->mutex_key);
		return (1);
	}
	pthread_mutex_unlock(&philo.data->mutex_key);
	return (0);
}

void *routine(void *args)
{
	t_philo	philo;

	philo = *(t_philo *)args;
	if (philo.id % 2 != 0)
			usleep(1000);
	while (1)
	{
		if (is_done(philo))
			break ;

		philo_eat(&philo);
		if (is_done(philo))
			break ;

		philo_sleep(philo);
		if (is_done(philo))
			break ;

		philo_think(philo);
		if (is_done(philo))
			break ;
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


