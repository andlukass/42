#include <stdio.h>
#include <unistd.h>

#include <stdarg.h>

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if ((char)c == s[index])
			return ((char *)(&s[index]));
		index++;
	}
	if ((char)c == s[index])
		return ((char *)(&s[index]));
	else
		return (0);
}

int c_specifier(char c)
{
    write(1, &c, 1);
    return (1);
}

int s_specifier(char *str)
{
    int index;

    index = 0;
    while (str[index])
    {
        write(1, &str[index], 1);
        index++;
    }
    return (index);
}

int p_specifier(void *adress)
{
    int index;

    index = 0;
    
    printf("%lu", (unsigned long int)adress);
    
    return (index);
}


int convertion(char c, va_list args)
{
    int length;

    if (c == 'c')
        length = c_specifier((char) va_arg(args, int));
    if (c == 's')
        length = s_specifier((char *) va_arg(args, char *));
    if (c == 'p')
        length = p_specifier((void *) va_arg(args, void *));
    if (c == 'd')
        write(1, &(char){'d'}, 1);
    if (c == 'i')
        write(1, &(char){'i'}, 1);
    if (c == 'u')
        write(1, &(char){'u'}, 1);
    if (c == 'x')
        write(1, &(char){'x'}, 1);
    if (c == 'X')
        write(1, &(char){'X'}, 1);
    if (c == '%')
        write(1, &(char){'%'}, 1);
    return (length);
}

int ft_printf(const char *restrict format, ...)
{
    va_list args;
    int index;
    int length;

    index = 0;
    length = 0;
    va_start(args, format);
    while (format[index])
    {
        if (format[index] == '%' && ft_strchr("cspdiuxX%", format[index + 1]))
        {
            length = length + convertion(format[index + 1], args);
            index++;
        }
        else
        {
            write(1 , &format[index], 1);
            length ++;
        }
        index++;
    }
    return (length);
}   

int main(void)
{
    int x = 42;
    ft_printf("vai da o %%%% %s, %p  %c cu\n", ",|||| minha pica kkk   ||||,", &x, '#');
    //printf("vai da o %%%%%% cu");


    // int* p = &x;
    // printf("Endereço de memória de x: %lu\n", (unsigned long int)&x);
    return 0;
}