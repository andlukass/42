#include "../ft_printf.h"

int xX_specifier(long int nbr, char c)
{
	unsigned long int index;
	unsigned long int length;
	unsigned long int nbr_final[50];

	index = 0;
	if (!nbr)
	{
		write(1, (const void *)"(nil)", 5);
		return (5);
	}
	// printf("\nADRESS:%lu\n", (unsigned long int)adress);
	// printf("NBR: %lu\n",nbr);
	// write(1, "0x", 2);
	while (nbr)
	{
		nbr_final[index] = nbr % 16;
		nbr = nbr / 16;
		index++;
	}
	// length = index + 2;
	length = index;
	if (c == 'x')
	{
		while (--index > 0)
			write(1, &(char *){"0123456789abcdef"}[nbr_final[index]], 1);
		write(1, &(char *){"0123456789abcdef"}[nbr_final[0]], 1);
	}
	else
	{
		while (--index > 0)
			write(1, &(char *){"0123456789ABCDEF"}[nbr_final[index]], 1);
		write(1, &(char *){"0123456789ABCDEF"}[nbr_final[0]], 1);
	}
	return (length);
}