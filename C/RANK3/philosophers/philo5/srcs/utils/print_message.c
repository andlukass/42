/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:25:00 by llopes-d          #+#    #+#             */
/*   Updated: 2023/10/14 17:02:28 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	print_message(int philo_id, char *action, long total_ms)
{
	write(1, ft_itoa(total_ms), strlen(ft_itoa(total_ms)));
	write(1, "\t", 1);
	write(1, ft_itoa(philo_id), strlen(ft_itoa(philo_id)));
	write(1, action, strlen(action));
}
