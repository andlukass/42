/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_counter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 18:26:12 by llopes-d          #+#    #+#             */
/*   Updated: 2023/09/26 14:10:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

static void	get_time(struct timeval *currentTime)
{
	if (gettimeofday(currentTime, NULL))
		exit(0);
}

void	*ms_counter(void *total_milliseconds)
{
	struct timeval	current_time;
	long	init_time;

	get_time(&current_time);
	init_time = (current_time.tv_sec * 1000);
	while (1)
	{
		get_time(&current_time);
		*((long long int *)total_milliseconds) = (current_time.tv_sec * 1000 + current_time.tv_usec / 1000) - init_time;
		// printf("Total Milliseconds since init: %lld\n", *((long long int *)total_milliseconds));
		usleep(1000);
	}
	return ((void *)0);
}