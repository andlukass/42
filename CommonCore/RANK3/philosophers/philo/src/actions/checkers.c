/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:28:37 by llopes-d          #+#    #+#             */
/*   Updated: 2023/11/05 13:01:22 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	is_satisfied(t_philo philo)
{
	if (philo.data->args.must_eat < 0)
		return (0);
	if (philo.meals >= philo.data->args.must_eat)
		return (1);
	return (0);
}

int	someone_died(t_data *data)
{
	int	someone_died;

	someone_died = 0;
	pthread_mutex_lock(&data->mutex);
	if (data->dead)
		someone_died = 1;
	pthread_mutex_unlock(&data->mutex);
	return (someone_died);
}
