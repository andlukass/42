/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-dstudent.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:31:47 by jpimente          #+#    #+#             */
/*   Updated: 2023/03/22 19:27:33 by jpimente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	diff;
	int	index;

	if (min >= max)
		return (0);
	index = 0;
	diff = max - min;
	*range = malloc(sizeof(int) * diff);
	if (*range == NULL)
		return (-1);
	while (min < max)
	{
		(*range)[index] = min;
		min++;
		index++;
	}
	return (diff);
}

int	main()
{	
	int *array;
	int min = 10;
	int max = 15;

	printf("%d,",ft_ultimate_range(&array, min, max));
 for(int i = 0; i < 5; i++)
	printf("%d,",array[i]);
}