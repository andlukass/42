/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:56:39 by llopes-d          #+#    #+#             */
/*   Updated: 2023/06/18 15:06:25 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

void teste1(char *buffer)
{
	int	index;
	int	flag;
	int	start;

	index = 0;
	flag = 0;
	start = 0;
	while (buffer[index])
	{
		if (buffer[index] == '\n' && !flag++)
			index++;
		if (flag)
			buffer[start++] = buffer[index];
		index++;
	}
	while (buffer[start])
		buffer[start++] = '\0';
}


void teste2(char *line)
{
	int	index;

	index = 0;
	while (line[index] && line[index] != '\n')
		index++;
	while (line[++index])
		line[index] = '\0';
}

int	main()
{
	// int		fd;
	// char	*t;
	// int		flag;

	// flag = 0;
	// fd = open("teste.txt", O_RDONLY);
	// for (int i = 0; i < 7; i++)
	// {
	// 	if (flag)
	// 		break;
	// 	t = get_next_line(fd);
	// 	printf("\nlinha %d: %s", i+1, t);
	// 	if (!t)
	// 		flag = 1;
	// 	//free(t);
	// }
	// //printf("linha: %s", get_next_line(fd));
	// close(fd);
	// return (0);
	char teste[] = "vai da o cu mano";
	teste2(teste);
	printf("%s\n", teste);
}
