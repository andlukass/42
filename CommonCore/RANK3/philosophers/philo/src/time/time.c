/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:29:57 by llopes-d          #+#    #+#             */
/*   Updated: 2023/11/05 14:02:12 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

long int	time_now(t_philo philo)
{
	long int		now;
	struct timeval	time;

	gettimeofday(&time, NULL);
	now = (time.tv_sec * 1000 + time.tv_usec / 1000);
	return (now - philo.data->init_time);
}

int	time_no_eat(t_philo philo)
{
	return (time_now(philo) - philo.last_eat);
}

int	time_thinking(t_philo philo)
{
	return (time_now(philo) - philo.last_think);
}

int	time_eating(t_philo philo)
{
	return (time_now(philo) - philo.last_eat);
}

int	time_sleeping(t_philo philo)
{
	return (time_now(philo) - philo.last_sleep);
}
