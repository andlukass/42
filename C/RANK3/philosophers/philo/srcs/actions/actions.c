/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:25:40 by user              #+#    #+#             */
/*   Updated: 2023/10/18 08:26:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	print_action(t_data *data, t_philo philo, char *action)
{
	pthread_mutex_lock(&data->mutex);
	if (!data->dead && !data->satisfied)
		printf("%ld\t%d %s\n", (get_time() - philo.data->init_time), \
				philo.id, action);
	if (strcmp(action, "died") == 0)
	{
		pthread_mutex_unlock(philo.next_fork);
		pthread_mutex_unlock(philo.own_fork);
		data->dead = 1;
	}
	pthread_mutex_unlock(&data->mutex);
}

static void philo_wait(t_philo philo, long time)
{
	long	when_die;
	long	diff;

	when_die = philo.last_eat + philo.data->arguments.time_to_die;
	diff = when_die - ((get_time() - philo.data->init_time));
	// printf("%d - when_die: %ld\n", philo.id, when_die);
	// printf("%d - now: %ld\n", philo.id, (get_time() - philo.data->init_time));
	// printf("%d - time: %ld\n", philo.id, time);
	// printf("%d - diff: %ld\n", philo.id, when_die - ((get_time() - philo.data->init_time)));
	if (time >= diff)
	{
		//se maior vai morrer
		usleep(diff * 1000);
		print_action(philo.data, philo, "died");
	}
	else //se menor, so dorme
	{	
		usleep(time * 1000);
	}
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->next_fork);
		print_action(philo->data, *philo, "has taken a fork");

	if (philo->data->arguments.number_of_philosophers == 1)
		philo_wait(*philo, philo->data->arguments.time_to_die);

	pthread_mutex_lock(philo->own_fork);
		print_action(philo->data, *philo, "has taken a fork");

	philo->meals++;
	philo->is_eating = 1;
	philo->last_eat = get_time() - philo->data->init_time;
	print_action(philo->data, *philo, "is eating");
	philo_wait(*philo, philo->data->arguments.time_to_eat);
}

void	philo_sleep(t_philo philo)
{
	pthread_mutex_unlock(philo.next_fork);
	pthread_mutex_unlock(philo.own_fork);
	philo.is_eating = 0;
	print_action(philo.data, philo, "is sleeping");
	philo_wait(philo, (philo.data->arguments.time_to_sleep));
}

void philo_think(t_philo philo)
{
	pthread_mutex_lock(&philo.data->mutex_key);
	if (philo.meals == philo.data->arguments.must_eat || philo.data->dead)
	{
		printf("philo: %d, encerrou2\n", philo.id);
		if (philo.is_eating == 1)
		{
			pthread_mutex_unlock(philo.next_fork);
			pthread_mutex_unlock(philo.own_fork);
		}
		pthread_mutex_unlock(&philo.data->mutex_key);
		exit (1);
	}
	pthread_mutex_unlock(&philo.data->mutex_key);
	print_action(philo.data, philo, "is thinking");
	philo_wait(philo, (philo.data->arguments.time_to_eat - philo.data->arguments.time_to_sleep));
}
