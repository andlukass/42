/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include <stdio.h>

char *ft_strchr(const char *s, int c)
{
	int index;

	index = 0;
	while (s[index])
	{
		if (c == s[index])
			return ((char *)(&s[index]));
		index++;
	}
	return ((c == s[index]) ? ((char *)(&s[index])) : 0);
}

/*int main()
{
	char test1[50] = "LETS TESS";

	printf("%s\n", ft_strchr(test1, '0'));
}*/
