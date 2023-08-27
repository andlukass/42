/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:40:12 by llopes-d          #+#    #+#             */
/*   Updated: 2023/08/27 17:48:39 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_char(char *str, char c)
{
	int	counter;
	int	index;

	index = 0;
	counter = 0;
	while (str[index])
	{
		if (str[index] == c)
			counter++;
		index++;
	}
	return (counter);
}
