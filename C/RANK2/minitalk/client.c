#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	result;
	int	negative;
	int	i;

	result = 0;
	i = 0;
	negative = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '-')
		negative *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		if (result == 0)
			result = str[i] - 48;
		else
			result = ((result * 10) + (str[i] - 48));
		i++;
	}
	return (result * negative);
}

void handler(int signal) {
    // Função de tratamento do sinal
    printf("DSA BDHABSJHDBAJSDBAS: %d\n", 100);
}

int	main(int argc, char *argv[])
{
	// struct sigaction sa = {0};
	// sa.sa_handler = &handler;
	// sa.sa_flags = 10;
	// sigaction(SIGUSR1, &sa, NULL);
	kill(ft_atoi(argv[1]), SIGUSR1);
	return 0;
}
