#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>

int c_specifier(char c);

int s_specifier(char *str);

int p_specifier(void *adress);

int di_specifier(int nb);

#endif