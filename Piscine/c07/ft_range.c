/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-dstudent.42lisboa.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:31:47 by jpimente          #+#    #+#             */
/*   Updated: 2023/03/22 19:27:33 by jpimente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	diff;
	int	index;

	index = 0;
	diff = max - min;
	array = malloc(sizeof(int) * diff);
	if (min >= max)
		return (0);
	while (min < max)
	{
		array[index] = min;
		min++;
		index++;
	}
	return (array);
}

 int	main()
{	
	int *array;
	int min = 10;
	int max = 15;
	int arr_size = (max - min);
	array = ft_range(min, max);
    for(int i = 0; i < arr_size; i++)
	printf("%d,",array[i]);
} 