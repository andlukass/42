/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:26:12 by llopes-d          #+#    #+#             */
/*   Updated: 2023/09/29 16:08:29 by user             ###   ########.fr       */
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
	long		number_of_philosophers;
	int			already_satisfied;
	int			someone_died;
	long		init_time;
	t_data		*data;

	data = (t_data *)args;
	init_time = get_time();
	number_of_philosophers = data->args.number_of_philosophers;
	while (1)
	{
		pthread_mutex_lock(&data->mutex);
		already_satisfied = data->already_satisfied;
		data->total_milliseconds = get_time() - init_time;
		someone_died = data->someone_died;
		pthread_mutex_unlock(&data->mutex);
		if (someone_died || already_satisfied == number_of_philosophers)
			break ;
	}
	return ((void *)0);
}
