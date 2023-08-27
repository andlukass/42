/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:32:56 by user              #+#    #+#             */
/*   Updated: 2023/08/27 18:07:36 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// print_stacks(data);

int	main(int argc, char *argv[])
{
	t_data	data;
	char	**arguments;
	int		length;

	if (argc == 0)
		return (0);
	arguments = handle_args(argc, argv, &length);
	if (!init_stacks(&data, length, arguments))
	{
		free_arguments(arguments);
		return (write(1, "error\n", 6));
	}
	if (length <= 25)
		sort_little(&data);
	else
		sort_large(&data);
	free_arguments(arguments);
	free_stack(data.stack_a);
}
