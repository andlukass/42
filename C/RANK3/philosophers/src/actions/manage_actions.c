/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 17:47:00 by user              #+#    #+#             */
/*   Updated: 2023/09/28 18:01:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	*manage_actions(void *args)
{
	int	index;
	long long int	total_milliseconds;
	int	someone_died;
	t_philosopher	*philo;
	t_data **data = (t_data **)&args;

	pthread_mutex_lock(&(*(data))->mutex);
	philo = &(*(data))->philo[(*(data))->philo_initiated++];
	pthread_mutex_unlock(&(*(data))->mutex);
	while (1)
	{
		pthread_mutex_lock(&(*(data))->mutex);
		total_milliseconds = (*(data))->total_milliseconds;
		pthread_mutex_unlock(&(*(data))->mutex);
		is_dead(philo, total_milliseconds);
		if (philo->is_dead)
		{
			pthread_mutex_lock(&(*(data))->mutex);
			(*(data))->someone_died = 1;
			pthread_mutex_unlock(&(*(data))->mutex);
			break;
		}
		pthread_mutex_lock(&(*(data))->mutex);
		someone_died = (*(data))->someone_died;
		pthread_mutex_unlock(&(*(data))->mutex);
		if (someone_died)
			break;
		if (!wake_up(philo, total_milliseconds))
			continue;
		pthread_mutex_lock(&(*(data))->mutex);
		get_fork(philo, &(*(data))->forks, total_milliseconds);
		get_sleep(philo, &(*(data))->forks, total_milliseconds);
		pthread_mutex_unlock(&(*(data))->mutex);
	}
	return (void *)0;
}
