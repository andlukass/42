/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #include <stdio.h>

char *ft_strrchr(const char *s, int c)
{
	char *final;
	int index;
	int count;

	index = 0;
	count = 0;
	while (s[index])
	{
		if (c == s[index])
		{
			final = ((char *)(&s[index]));
			count++;
		}
		index++;
	}
	if (count)
		return (final);
	return ((c == s[index]) ? ((char *)(&s[index])) : 0);
}

/*int main()
{
	char test1[50] = "LETS TESS";

	printf("%s\n", ft_strrchr(test1, '0'));
}*/
