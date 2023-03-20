/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:53:59 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/14 14:54:03 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	get_length(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		index++;
	}
	return (index);
}

int	compare(char *str, char *to_find, int index)
{
	int	result;
	int	to_find_length;
	int	j;

	to_find_length = get_length(to_find);
	result = 0;
	j = 0;
	while (j < to_find_length)
	{
		if (to_find[j] == str[index])
		{
			result = 1;
		}
		else
		{
			return (0);
		}
		j++;
		index++;
	}
	return (result);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	str_index;
	int	find_index;

	str_index = 0;
	find_index = 0;
	if (to_find[str_index] == '\0')
		return (&str[str_index]);
	while (str[str_index] != '\0')
	{
		while (to_find[find_index] != '\0')
		{
			if (str[str_index] == to_find[find_index])
			{
				if (compare(str, to_find, str_index))
				{
					return (&str[str_index]);
				}
			}
			find_index++;
		}
		find_index = 0;
		str_index++;
	}
	return (0);
}

/*int	main()
{
	char test1[50] = "LETS TEST IT";
	char test2[50] = "_";


	printf("%s\n", ft_strstr(test1, test2));
	printf("%s\n", ft_strstrr(test1, test2));
}*/
