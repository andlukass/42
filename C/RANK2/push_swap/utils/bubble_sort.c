/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 09:04:44 by user              #+#    #+#             */
/*   Updated: 2023/08/24 13:42:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	bubble_sort(int *array, int length)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while(i < length)
	{
		j = i + 1;
		while(j < length)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
}
