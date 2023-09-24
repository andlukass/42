/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 16:07:23 by user              #+#    #+#             */
/*   Updated: 2023/09/24 11:50:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	is_arguments_empty(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	return (0);
}

t_args	getArgs(int argc, char *argv[])
{
	t_args args;

	args.number_of_philosophers = ft_atoi(argv[1]);
	args.time_to_die = ft_atoi(argv[2]);
	args.time_to_eat = ft_atoi(argv[3]);
	args.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		args.number_of_philosophers = ft_atoi(argv[5]);
		args.has_last_argument++;
	}
	else
	{
		args.number_of_times_each_philosopher_must_eat = 0;
		args.has_last_argument = 0;
	}
	return (args);
}

void	getTime(struct timeval *currentTime)
{
	if (gettimeofday(currentTime, NULL))
		exit(0);
}

int main(int argc, char *argv[])
{
	struct timeval currentTime;
	t_args args;
	t_philosopher philo;

	if((argc != 5 && argc != 6) || is_arguments_empty(argc, argv))
		return (0);
	
	args = getArgs(argc, argv);

	
	
}