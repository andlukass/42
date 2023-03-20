/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-dstudent.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:27:32 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/16 17:27:34 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	index;

	(void)argc;
	index = 0;
	while (argv[0][index])
	{
		write(1, &argv[0][index], 1);
		index++;
	}
	write(1, "\n", 1);
	return (0);
}
