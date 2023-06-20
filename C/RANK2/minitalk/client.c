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

int	send_message(int pid, char a)
{
	int bit = 7;
	while(bit >= 0)
	{
		if((a >> bit) & 1)
			kill(pid, SIGUSR1);//1
		else
			kill(pid, SIGUSR2);//0
		usleep(100);
		bit--;
	}
	return 0;
}
//0110 0001
int	main(int argc, char *argv[])
{
	int i = 0;
	if (argc != 3)
		return (1);
	while(argv[2][i])
	{
		send_message((ft_atoi(argv[1])), argv[2][i]);
		i++;
	}
	return 0;
}
// SIGUSR1 -- 10
// SIGUSR2 -- 12

//0110 0001 = a
