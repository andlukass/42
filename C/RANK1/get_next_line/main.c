/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 21:56:39 by llopes-d          #+#    #+#             */
/*   Updated: 2023/06/04 21:57:24 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*t;
	int		flag;

	flag = 0;
	fd = open("teste.txt", O_RDONLY);
	for (int i = 0; i < 7; i++)
	{
		if (flag)
			break;
		t = get_next_line(fd);
		printf("\nlinha %d: %s", i+1, t);
		if (!t)
			flag = 1;
		free(t);
	}
	//printf("linha: %s", get_next_line(fd));
	close(fd);
	return (0);
}
