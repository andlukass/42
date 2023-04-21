/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42lisboa.com >  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/06 17:36:10 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int		unleah(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (-1);
}

static int		count_words(const char *str, char charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == charset || str[i + 1] == '\0') == 1
				&& (str[i] == charset || str[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void		write_word(char *dest, const char *from, char charset)
{
	int	i;

	i = 0;
	while ((from[i] == charset || from[i] == '\0') == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int		write_split(char **split, const char *str, char charset)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == charset || str[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((str[i + j] == charset || str[i + j] == '\0') == 0)
				j++;
			if ((split[word] = (char*)malloc(sizeof(char) * (j + 1))) == NULL)
				return (unleah(split, word - 1));
			write_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
	return (0);
}

char			**ft_splite(const char *str, char c)
{
	char	**res;
	int		words;

	words = count_words(str, c);
	if ((res = (char**)malloc(sizeof(char*) * (words + 1))) == NULL)
		return (NULL);
	res[words] = 0;
	if (write_split(res, str, c) == -1)
		return (NULL);
	return (res);
}


char	**ft_split(char const *s, char c)
{
	int index;
	int k;
	int start;
	int length;
	int word;
	char **newstr;

	k = 0;
	start = 0;
	length = 0;
	index = 0;
	word = 0;
	while (s[index] && s[index] == c) //pular quando ja comeca com o char
		index++;
	while (s[index])//conta as vezes que o char aparece
	{
		if (s[index] == c && (s[index+1] != c && s[index+1]))
			word++;
		index++;
	}
	if (word == 0)
		return NULL;
	newstr = malloc((word + 2) * sizeof(char *));//+2 pq conta a primeira palavra + o \0
	//A PARTIR DAQUI TEMOS O MALLOC DE CADA PALAVRA EXISTENTE
	//MAS FALTA O MALLOC DE CADA CHAR

	// word = 0;
	// index = 0;
	// while (s[index] && s[index] == c)
	// 	index++;
	// start = index;
	// while (s[index])
	// {
	//  	if (s[index] == c && (s[index+1] != c && s[index+1]))
	//  	{
	// printf("\nchar'%c'\n", s[index]);
	// printf("index'%d'\n", index);

	// 		//printf("new string is from %d to %d\n", start, index-1);
	// 		newstr[word] = malloc(( ((index) - start) + 1) * sizeof(char));
	// 		//printf("\nword'%d'\n", ((index-1) - start));
	// 		while (start < (index))
	// 		{
	// 			newstr[word][k] = s[start];
	// 			k++;
	// 			start++;
	// 		}
	// 		newstr[word][k] = '\0';
	// 		start++;
	// 		k = 0;
	// 		word++;
	// 	}
	// 	index++;
	//  }
	// newstr[word] = malloc(( ((index) - start) + 1) * sizeof(char));
	// while (start < (index) && (s[start] != c && s[start]))
	// {
	// 	newstr[word][k] = s[start];
	// 	k++;
	// 	start++;
	// }
	// newstr[word][k] = '\0';
	return (newstr);
}

int main()
{
	char *str = "tripouille    42               5               ";
    char **result = ft_split(str, ' ');
	//char **result;

	//result[0] = "vai da o cu";
	  //printf("'%s'\n", result[0]);
    int i = 0;
    while (result[i])
    {
        printf("'%s'\n", result[i]);
       i++;
   }
}
