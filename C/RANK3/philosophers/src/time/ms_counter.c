/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:26:12 by llopes-d          #+#    #+#             */
/*   Updated: 2023/09/28 19:03:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static long int	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*ms_counter(void *args)
{
	long int	current_time;
	long int	init_time;
	int			someone_died;
	t_data		*data;

	data = (t_data *)args;
	init_time = get_time();
	while (1)
	{
		current_time = get_time();
		pthread_mutex_lock(&data->mutex);
		data->total_milliseconds = current_time - init_time;
		pthread_mutex_unlock(&data->mutex);
		pthread_mutex_lock(&data->mutex);
		someone_died = data->someone_died;
		pthread_mutex_unlock(&data->mutex);
		if (someone_died)
			break ;
	}
	return ((void *)0);
}
