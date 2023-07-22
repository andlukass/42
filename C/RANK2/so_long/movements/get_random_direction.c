#include "../so_long.h"

char get_random_direction(int time)
{
	double numeroAleatorio = sin(time);  // Obtém um valor entre -1 e 1
	int numero = (int)(fabs(numeroAleatorio) * 4) + 1;
	
	if (numero == 1)
		return ('u');
	if (numero == 2)
		return ('d');
	if (numero == 3)
		return ('l');
	if (numero == 4)
		return ('r');
	return ('0');
}