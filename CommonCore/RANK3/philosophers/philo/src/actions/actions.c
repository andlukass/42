/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:25:40 by user              #+#    #+#             */
/*   Updated: 2023/11/14 17:02:57 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	print_action(t_data *data, t_philo philo, char *action)
{
	pthread_mutex_lock(&data->mutex);
	if (!data->dead)
		printf("%ld\t%d %s\n", time_now(philo), philo.id, action);
	if (action[0] == 'd')
		data->dead = 1;
	pthread_mutex_unlock(&data->mutex);
}

void	philo_die(t_philo philo)
{
	if (time_no_eat(philo) >= philo.data->args.time_to_die)
		print_action(philo.data, philo, "died");
}

void	philo_eat(t_philo *philo)
{
	if (philo->status != THINKING || philo->data->args.number_of_philo == 1)
		return ;
	if (time_thinking(*philo) <= philo->data->args.time_to_think \
			&& philo->last_think != 0)
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks_mutex[philo->own_fork]);
		print_action(philo->data, *philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->forks_mutex[philo->next_fork]);
		print_action(philo->data, *philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks_mutex[philo->next_fork]);
		print_action(philo->data, *philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->forks_mutex[philo->own_fork]);
		print_action(philo->data, *philo, "has taken a fork");
	}
	philo->meals++;
	philo->last_eat = time_now(*philo);
	philo->status = EATING;
	print_action(philo->data, *philo, "is eating");
}

void	philo_sleep(t_philo *philo)
{
	if (philo->status != EATING || \
	philo->data->args.number_of_philo == 1)
		return ;
	if (time_eating(*philo) >= philo->data->args.time_to_eat)
	{
		pthread_mutex_unlock(&philo->data->forks_mutex[philo->own_fork]);
		pthread_mutex_unlock(&philo->data->forks_mutex[philo->next_fork]);
		philo->status = SLEEPING;
		philo->last_sleep = time_now(*philo);
		print_action(philo->data, *philo, "is sleeping");
	}
}

void	philo_think(t_philo *philo)
{
	if (philo->status != SLEEPING || \
	philo->data->args.number_of_philo == 1)
		return ;
	if (time_sleeping(*philo) > philo->data->args.time_to_sleep)
	{
		philo->status = THINKING;
		philo->last_think = time_now(*philo);
		print_action(philo->data, *philo, "is thinking");
	}
}
