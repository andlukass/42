/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-dstudent.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:45:58 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/16 17:46:04 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_arg(char *argv[], int arg_index)
{
	int	index;

	index = 0;
	while (argv[arg_index][index])
	{
		write(1, &argv[arg_index][index], 1);
		index++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	index;

	index = 1;
	while (index < argc)
	{
		write_arg(argv, index);
		index++;
	}
	return (0);
}
