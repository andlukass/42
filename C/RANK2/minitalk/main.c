

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void signal_handler(int sig) {
	printf("Sinal SIGUSR1 recebido: %d\n", sig);
}

int	main()
{
	int x = getpid();
	signal(SIGUSR1, signal_handler);
	printf("pid: %d\n waiting for message...", x);
	write(1, "waiting for message...", 23);
	while(1)
	{
		sleep(1);
	}
}
