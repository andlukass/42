#include "../ft_printf.h"

int p_specifier(void *adress)
{
	unsigned long int index;
	unsigned long int length;
	unsigned long int nbr;
	unsigned long int nbr_final[50];

	index = 0;
	nbr = (unsigned long int)adress;
	// printf("\nADRESS:%lu\n", (unsigned long int)adress);
	// printf("NBR: %lu\n",nbr);
	write(1, "0x", 2);
	while (nbr)
	{
		nbr_final[index] = nbr % 16;
		nbr = nbr / 16;
		index++;
	}
	length = index + 2;
	while (--index > 0)
		write(1, &(char *){"0123456789abcdef"}[nbr_final[index]], 1);
	write(1, &(char *){"0123456789abcdef"}[nbr_final[0]], 1);
	return (length);
}
