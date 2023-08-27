/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 15:43:23 by llopes-d          #+#    #+#             */
/*   Updated: 2023/08/27 17:48:18 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_words(char *str)
{
	int	index;
	int	words;

	index = 0;
	words = 0;
	while (str[index])
	{
		if (str[index] != ' ' && (str[index + 1] == ' '
				|| str[index + 1] == '\0'))
			words++;
		index++;
	}
	return (words);
}
