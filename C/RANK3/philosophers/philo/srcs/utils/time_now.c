/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_now.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:29:57 by llopes-d          #+#    #+#             */
/*   Updated: 2023/10/24 17:02:54 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

long int	time_now(t_philo philo)
{
	return (get_time() - philo.data->init_time);
}
