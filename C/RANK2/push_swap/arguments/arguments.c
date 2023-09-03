/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:52:42 by llopes-d          #+#    #+#             */
/*   Updated: 2023/09/03 14:18:37 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	arg_count(int argc, char *argv[])
{
	int	index;
	int	spaces;
	int	length;

	index = 1;
	length = 0;
	while (index < argc)
	{
		spaces = count_char(argv[index], ' ');
		if (spaces)
			length = length + count_words(argv[index]);
		else
			length++;
		index++;
	}
	return (length);
}

static int	get_sub_args(char *arguments[], char *argv[], int *index, int *j)
{
	int	spaces;
	int	init;
	int	k;

	k = 0;
	spaces = count_char(argv[*index], ' ');
	while (spaces)
	{
		while (argv[*index][k] == ' ')
			k++;
		init = k;
		while (argv[*index][k] != ' ' && argv[*index][k] != '\0')
			k++;
		spaces = count_char(&argv[*index][k], ' ');
		if (!argv[*index][k] && argv[*index][k - 1] == ' ')
			continue ;
		arguments[*j] = ft_strdup(&argv[*index][init], k - init);
		*j = *j + 1;
	}
	return (k);
}

static void	get_args(int argc, char *argv[], char *arguments[])
{
	int	index;
	int	j;
	int	k;

	index = 1;
	j = 0;
	while (index < argc)
	{
		k = get_sub_args(arguments, argv, &index, &j);
		if (!k)
			arguments[j++] = ft_strdup(argv[index], strlen(argv[index]));
		index++;
	}
	arguments[j] = NULL;
}

char	**handle_args(int argc, char *argv[], int *length)
{
	char	**arguments;

	*length = arg_count(argc, argv);
	arguments = malloc(sizeof(char *) * (*length + 1));
	if (!arguments)
		return (ERROR);
	get_args(argc, argv, arguments);
	return (arguments);
}

void	free_arguments(char **arguments)
{
	int	index;

	index = 0;
	while (arguments[index])
		free(arguments[index++]);
	free(arguments);
}
