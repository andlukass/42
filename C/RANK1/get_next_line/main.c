#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *t;

	fd = open("teste.txt", O_RDONLY);
	for (int i = 0; i < 4; i++)
	{
		t = get_next_line(fd);
		printf("linha %d: %s", i+1, t);
		free(t);
	}
	close(fd);
}
