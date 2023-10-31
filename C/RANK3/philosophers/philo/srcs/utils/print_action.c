/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:40:34 by llopes-d          #+#    #+#             */
/*   Updated: 2023/10/31 18:41:06 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	print_action(t_data *data, t_philo philo, char *action)
{
	pthread_mutex_lock(&data->mutex);
	if (!data->dead)
		printf("%ld\t%d %s\n", time_now(philo), philo.id, action);
	if (action[0] == 'd')
		data->dead = 1;
	pthread_mutex_unlock(&data->mutex);
}
