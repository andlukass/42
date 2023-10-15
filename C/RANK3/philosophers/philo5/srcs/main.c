/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 15:21:14 by llopes-d          #+#    #+#             */
/*   Updated: 2023/10/15 20:16:37 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void get_forks(t_philo *philo)
{
	pthread_mutex_t *next_fork;
	pthread_mutex_t *own_fork;

	own_fork = &philo->data->forks_mutex[philo->id - 1];
	if (philo->id == philo->data->arguments.number_of_philosophers)
		next_fork = &philo->data->forks_mutex[0];
	else
		next_fork = &philo->data->forks_mutex[philo->id];

	pthread_mutex_lock(next_fork);
		printf("%ld\t%d has taken a fork\n", (get_time() - philo->data->init_time), philo->id);
		philo->forks++;
		//eat(philo);

	pthread_mutex_lock(own_fork);
		printf("%ld\t%d has taken a fork\n", (get_time() - philo->data->init_time), philo->id);
		philo->last_eat = get_time() - philo->data->init_time;
		philo->forks++;
		//eat(philo);

	printf("%ld\t%d is eating\n", (get_time() - philo->data->init_time), philo->id);

}

void	philo_sleep(t_philo *philo)
{
	pthread_mutex_t *next_fork;
	pthread_mutex_t *own_fork;

	own_fork = &philo->data->forks_mutex[philo->id - 1];
	if (philo->id == philo->data->arguments.number_of_philosophers)
		next_fork = &philo->data->forks_mutex[0];
	else
		next_fork = &philo->data->forks_mutex[philo->id];

	pthread_mutex_unlock(next_fork);
	pthread_mutex_unlock(own_fork);
	printf("%ld\t%d is sleeping\n", (get_time() - philo->data->init_time), philo->id);
	usleep(philo->data->arguments.time_to_sleep * 999);
}

void ft_usleep(t_philo *philo, long time)
{
	long	time_no_eat;
	long	when_die;
	long	diff;
	
	time_no_eat = (get_time() - philo->data->init_time) - philo->last_eat;
	when_die = philo->last_eat + philo->data->arguments.time_to_die;
	diff = when_die - ((get_time() - philo->data->init_time));
	// printf("when_die: %ld\n", when_die);
	// printf("time: %ld\n", time);
	// printf("diff: %ld\n", when_die - ((get_time() - philo->data->init_time)));
	if (time >= diff)
	{
		//se maior vai morrer
		usleep(diff * 998);
		printf("%ld\t%d died\n", (get_time() - philo->data->init_time), philo->id);
		exit(0);
	}
	else
	{
		usleep(time * 998);
		//se menor, so dorme
	}
	// if (time_no_eat >= philo->data->arguments.time_to_die)
	// {

	// }
}


void *routine(void *args)
{
	t_data	*data;
	t_philo	philo;
	
	philo = *(t_philo *)args;
	data = philo.data;
	if (philo.id % 2 != 0)
			usleep(1000);
	while (1)
	{
		get_forks(&philo);
		ft_usleep(&philo, data->arguments.time_to_eat);
		philo_sleep(&philo);
		// break ;

		// printf("philo: %d, last eat: %ld\n", philo.id, philo.last_eat);
	}

	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		number_of_philosophers;
	int		i;

	number_of_philosophers = init_variables(&data, argc, argv);


	pthread_mutex_init(&data.mutex, NULL);
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
	return (0);
} 


