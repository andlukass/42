/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:29:57 by llopes-d          #+#    #+#             */
/*   Updated: 2023/10/31 18:42:40 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	ft_wait(t_philo philo, long time)
{
	long	when_die;
	long	diff;

	when_die = philo.last_eat + philo.data->arguments.time_to_die;
	diff = when_die - (time_now(philo));
	if (time >= diff)
	{
		usleep(diff * 1000);
		print_action(philo.data, philo, "died");
	}
	else
		usleep(time * 1000);
}
