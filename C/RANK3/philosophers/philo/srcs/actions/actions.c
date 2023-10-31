/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:25:40 by user              #+#    #+#             */
/*   Updated: 2023/10/31 18:42:00 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	philo_die(t_philo philo)
{
	int	time_no_eat;

	time_no_eat = time_now(philo) - philo.last_eat;
	if (time_no_eat >= philo.data->arguments.time_to_die)
		print_action(philo.data, philo, "died");
}

void	philo_eat(t_philo *philo)
{
	if (philo->status != THINKING || \
	philo->data->arguments.number_of_philosophers == 1)
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
	int	time_eating;

	if (philo->status != EATING || \
	philo->data->arguments.number_of_philosophers == 1)
		return ;
	time_eating = time_now(*philo) - philo->last_eat;
	if (time_eating >= philo->data->arguments.time_to_eat)
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
	int	time_spent_sleeping;

	if (philo->status != SLEEPING || \
	philo->data->arguments.number_of_philosophers == 1)
		return ;
	time_spent_sleeping = time_now(*philo) - philo->last_sleep;
	if (time_spent_sleeping > philo->data->arguments.time_to_sleep)
	{
		philo->status = THINKING;
		print_action(philo->data, *philo, "is thinking");
		if (philo->data->arguments.number_of_philosophers % 2 == 0)
			ft_wait(*philo, philo->data->arguments.time_to_eat - 
				philo->data->arguments.time_to_sleep);
		else
			ft_wait(*philo, philo->data->arguments.time_to_eat);
	}
}
