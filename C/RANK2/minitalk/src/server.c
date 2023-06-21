/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:48:54 by llopes-d          #+#    #+#             */
/*   Updated: 2023/06/21 18:46:38 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	pid_t		sender_pid;
	static char	binary[9];
	static int	index;
	int			decimal;
	char		character;

	(void)context;
	sender_pid = info->si_pid;
	if (sig == 10)
		binary[index++] = '1';
	else
		binary[index++] = '0';
	if (index == 8)
	{	
		binary[index] = '\0';
		decimal = ft_atoi_base(binary, 2);
		character = (char)decimal;
		write(1, &character, 1);
		index = 0;
		kill(sender_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;
	char				*buffer;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	buffer = ft_itoa(getpid());
	write(1, "process id: ", 13);
	write(1, buffer, ft_strlen(buffer));
	write(1, "\nwaiting for message...\n", 25);
	free(buffer);
	while (1)
		sleep(1);
	return (0);
}
