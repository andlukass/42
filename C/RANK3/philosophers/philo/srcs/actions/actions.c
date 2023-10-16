/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:25:40 by user              #+#    #+#             */
/*   Updated: 2023/10/16 20:25:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	print_action(t_data *data, t_philo philo, char *action)
{
	if (!data->dead && !data->satisfied)
		printf("%ld\t%d %s\n", (get_time() - philo.data->init_time), \
				philo.id, action);
}

static void philo_wait(t_philo philo, long time)
{
	long	when_die;
	long	diff;

	when_die = philo.last_eat + philo.data->arguments.time_to_die;
	diff = when_die - ((get_time() - philo.data->init_time));
	// printf("when_die: %ld\n", when_die);
	// printf("time: %ld\n", time);
	// printf("diff: %ld\n", when_die - ((get_time() - philo.data->init_time)));
	if (time >= diff)
	{
		//se maior vai morrer
		usleep(diff * 1000);
		print_action(philo.data, philo, "died");
		exit(0);
	}
	else //se menor, so dorme
		usleep(time * 1000);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->next_fork);
		print_action(philo->data, *philo, "has taken a fork");

	if (philo->data->arguments.number_of_philosophers == 1)
		philo_wait(*philo, philo->data->arguments.time_to_die);

	pthread_mutex_lock(philo->own_fork);
		print_action(philo->data, *philo, "has taken a fork");

	philo->last_eat = get_time() - philo->data->init_time;
	print_action(philo->data, *philo, "is eating");
	philo_wait(*philo, philo->data->arguments.time_to_eat);
}

void	philo_sleep(t_philo philo)
{
	pthread_mutex_unlock(philo.next_fork);
	pthread_mutex_unlock(philo.own_fork);
	print_action(philo.data, philo, "is sleeping");
	philo_wait(philo, (philo.data->arguments.time_to_sleep));
}

void philo_think(t_philo philo)
{
	print_action(philo.data, philo, "is thiking");
	if (philo.data->arguments.number_of_philosophers % 2 != 0)
		philo_wait(philo, (philo.data->arguments.time_to_eat));
}