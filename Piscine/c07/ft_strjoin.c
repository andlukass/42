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

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

int	get_full_length(int size, char **strs, char *sep)
{
	int	index;
	int	lengs;

	index = 0;
	while (index < size)
	{
		lengs = lengs + ft_strlen(strs[index]);
		index++;
	}
	lengs = lengs + ft_strlen(sep);
	return (lengs);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		index;
	int		index2;
	int		final_index;
	char	*final_string;

	final_string = malloc(sizeof(char)
			* get_full_length(size, strs, sep) + 1);
	index = 0;
	final_index = 0;
	while (index < size)
	{
		index2 = 0;
		while (index2 < ft_strlen(strs[index]))
			final_string[final_index++] = strs[index][index2++];
		index2 = 0;
		if (index < (size - 1))
		{
			while (index2 < ft_strlen(sep))
				final_string[final_index++] = sep[index2++];
		}
		index++;
	}
	final_string[final_index] = '\0';
	return (final_string);
}

int	main()
{	
	char    *strs[] = {"test1", "test2", "test3"};
	char    sep[] = " / ";

	printf("%s", ft_strjoin(3, strs, sep));
}