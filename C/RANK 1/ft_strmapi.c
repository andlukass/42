/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*newstr;
	int		index;
	int		length;

	index = 0;
	length = 0;
	while (s[length])
		length++;
	newstr = (char *) malloc((length + 1) * sizeof(char));
	if (newstr == NULL)
		return (NULL);
	while (s[index])
	{
		newstr[index] = (*f)(index, s[index]);
		index++;
	}
	newstr[index] = '\0';
	return (newstr);
}

//passes each char in the F func, dinamic allocation the new string
