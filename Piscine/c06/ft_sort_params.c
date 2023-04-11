/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-dstudent.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:45:58 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/16 17:46:04 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	index;

	index = 0;
	while (s1[index] == s2[index] && (s1[index] != '\0' || s2[index] != '\0'))
	{
		index++;
	}
	return (s1[index] - s2[index]);
}

void	swap(char *argv[], int index)
{
	char	*buff;

	buff = argv[index + 1];
	argv[index + 1] = argv[index];
	argv[index] = buff;
}

void	compare(int argc, char *argv[])
{
	int	aindex;
	int	cindex;
	int	j;
	int	diff;

	aindex = 1;
	cindex = 0;
	j = 1;
	while (j < argc)
	{
		aindex = 1;
		while (aindex < argc - 1)
		{
			diff = ft_strcmp(argv[aindex], argv[aindex + 1]);
			if (diff > 0)
			{
				swap(argv, aindex);
			}
			aindex++;
		}
		j++;
	}
}

void	write_arg(char *argv[], int aindex)
{
	int	index;

	index = 0;
	while (argv[aindex][index])
	{
		write(1, &argv[aindex][index], 1);
		index++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	index;

	compare(argc, argv);
	index = 1;
	while (index < argc)
	{
		write_arg(argv, index);
		index++;
	}
	return (0);
}
