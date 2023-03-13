/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:33:39 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/08 20:33:52 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*#include <stdio.h>*/

int	is_alpha(char c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

void	make_upper_case(char *str)
{
	if (*str >= 65 && *str <= 90)
	{
		*str = (*str + 32);
	}
}

char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{	
		if (str[index] >= 97 && str[index] <= 122)
		{
			str[index] = (str[index] - 32);
		}
		make_upper_case(&str[index]);
		if (is_alpha(str[index - 1]) == 0)
		{
			if (str[index] >= 97 && str[index] <= 122)
			{
				str[index] = (str[index] - 32);
			}
		}
		index++;
	}
	return (str);
}

/*int main()
{
	char teste[60] = "/LE_TS TE/ST IT togheEETher?";
	printf("%s\n",ft_strcapitalize(teste));
}*/
