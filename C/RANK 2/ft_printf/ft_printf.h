#ifndef PRINTF_H
#define PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

// #include "./specifiers/c_specifier.c"
// #include "./specifiers/s_specifier.c"
// #include "./specifiers/p_specifier.c"
// #include "./specifiers/di_specifier.c"
// #include "./specifiers/u_specifier.c"
// #include "./specifiers/xX_specifier.c"

int c_specifier(char c);

int s_specifier(char *str);

int p_specifier(void *adress);

int di_specifier(int nb);

int u_specifier(long int nb);

int xX_specifier(long int nbr, char c);

int ft_printf(const char *format, ...);

#endif