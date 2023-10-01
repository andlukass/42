/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:47:00 by user              #+#    #+#             */
/*   Updated: 2023/09/29 16:21:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static long int	get_total_ms(t_data *data)
{
	long int	total_milliseconds;

	pthread_mutex_lock(&data->mutex);
	total_milliseconds = data->total_milliseconds;
	pthread_mutex_unlock(&data->mutex);
	return (total_milliseconds);
}

static t_philosopher	*get_philo(t_data *data)
{
	t_philosopher	*philo;

	pthread_mutex_lock(&data->mutex);
	philo = &data->philo[data->philo_initiated++];
	pthread_mutex_unlock(&data->mutex);
	return (philo);
}

static int	someone_died(t_data *data, int is_dead)
{
	int	someone_died;

	if (is_dead)
	{
		pthread_mutex_lock(&data->mutex);
		data->someone_died = 1;
		pthread_mutex_unlock(&data->mutex);
		return (1);
	}
	pthread_mutex_lock(&data->mutex);
	someone_died = data->someone_died;
	pthread_mutex_unlock(&data->mutex);
	if (someone_died)
		return (1);
	return (0);
}

static int	is_satisfied(t_data *data, t_philosopher philo)
{
	int	must_eat;

	must_eat = philo.args.number_of_times_each_philosopher_must_eat;
	if (must_eat && philo.number_of_meals >= must_eat && philo.is_sleeping)
	{
		pthread_mutex_lock(&data->mutex);
		data->already_satisfied++;
		pthread_mutex_unlock(&data->mutex);
		return (1);
	}
	return (0);
}

void	*manage_actions(void *args)
{
	t_philosopher	*philo;
	t_data			*data;
	long int		total_milliseconds;

	data = (t_data *)args;
	philo = get_philo(data);
	while (1)
	{
		total_milliseconds = get_total_ms(data);
		is_dead(philo, total_milliseconds);
		if (someone_died(data, philo->is_dead))
			break ;
		if (!wake_up(philo, total_milliseconds))
			continue ;
		pthread_mutex_lock(&data->mutex);
		get_fork(philo, &data->forks, total_milliseconds);
		get_sleep(philo, &data->forks, total_milliseconds);
		pthread_mutex_unlock(&data->mutex);
		if (is_satisfied(data, *philo))
			break ;
	}
	return (NULL);
}
