

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>

#include <stdlib.h>

void signal_handler(int sig) {
	static char c[9];
	static int index;
	int binary = 0;
	char character; 
	if (sig == 10)
	{
		c[index] = '1';
		//write(1, "1", 1);
		index++;
	}
	else
	{
		c[index] = '0';
		//write(1, "0", 1);
		index++;
	}
	if (index == 7)
	{	
		c[8] = '\0';
		//binary = atoi(c);
		write(1, &c , strlen(c));
		// binary = strtoul(c, NULL, 2);
		bzero(c, strlen(c));
		// character = (char)binary;
		// write(1, &character, 1);
		index = 0;
	}
}

int	main(void)
{
	int x = getpid();
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	printf("pid: %d\n", x);
	printf("waiting for message...\n");
	while(1)
		sleep(1);
	return (0);
}
