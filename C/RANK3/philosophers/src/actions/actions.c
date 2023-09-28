/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:10:37 by user              #+#    #+#             */
/*   Updated: 2023/09/28 21:05:02 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	is_dead(t_philosopher *philo, long total_ms)
{
	int	time_no_eat;
	int	last_time_eat;

	if (philo->last_time_get_fork <= 0)
		last_time_eat = 0;
	else
		last_time_eat = philo->last_time_get_fork + philo->args.time_to_eat;
	time_no_eat = total_ms - last_time_eat;
	if (time_no_eat >= philo->args.time_to_die)
	{
		printf("%ld %d died\n", total_ms, philo->id);
		philo->is_dead = 1;
	}
}

int	wake_up(t_philosopher *philo, long total_ms)
{
	int	is_wake_up;
	int	time_spent_sleeping;

	if (!philo->is_sleeping)
	{
		is_wake_up = 1;
		return (is_wake_up);
	}
	time_spent_sleeping = total_ms - philo->last_time_went_sleep;
	if (time_spent_sleeping >= philo->args.time_to_sleep)
	{
		philo->is_sleeping = 0;
		is_wake_up = 1;
		printf("%ld %d is thinking\n", total_ms, philo->id);
	}
	else
		is_wake_up = 0;
	return (is_wake_up);
}

void	get_sleep(t_philosopher *philo, t_fork **forks, long total_ms)
{
	int		time_eating;
	int		next_fork;
	t_fork	*deref_forks;

	deref_forks = *forks;
	if (philo->id == philo->args.number_of_philosophers)
		next_fork = 0;
	else
		next_fork = philo->id;
	if (philo->number_of_forks == 2)
		time_eating = total_ms - philo->last_time_get_fork;
	else
		time_eating = 0;
	if (time_eating >= philo->args.time_to_eat)
	{
		printf("%ld %d is sleeping\n", total_ms, philo->id);
		deref_forks[philo->id - 1].is_on_table = 1;
		deref_forks[next_fork].is_on_table = 1;
		philo->number_of_forks = 0;
		philo->is_sleeping = 1;
		philo->last_time_went_sleep = total_ms;
	}
}

void	get_fork(t_philosopher *philo, t_fork **forks, long total_ms)
{
	t_fork	*deref_forks;
	int		next_fork;

	deref_forks = *forks;
	if (philo->id == philo->args.number_of_philosophers)
		next_fork = 0;
	else
		next_fork = philo->id;
	if (philo->number_of_forks < 1 && deref_forks[philo->id - 1].is_on_table)
	{
		printf("%ld %d has taken 1º a fork: %d\n",
			total_ms, philo->id, deref_forks[philo->id - 1].id);
		deref_forks[philo->id - 1].is_on_table = 0;
		philo->number_of_forks++;
	}
	if (philo->number_of_forks == 1 && deref_forks[next_fork].is_on_table)
	{
		printf("%ld %d has taken 2º a fork: %d\n",
			total_ms, philo->id, deref_forks[next_fork].id);
		philo->last_time_get_fork = total_ms;
		deref_forks[next_fork].is_on_table = 0;
		philo->number_of_forks++;
		printf("%ld %d is eating\n", total_ms, philo->id);
	}
}
