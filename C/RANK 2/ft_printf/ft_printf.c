#include "ft_printf.h"

char *ft_strchr(const char *s, int c)
{
    int index;

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

int convertion(char c, va_list args)
{
    int length;

    length = 0;
    if (c == 'c')
        length = c_specifier((char)va_arg(args, int));
    if (c == 's')
        length = s_specifier((char *)va_arg(args, char *));
    if (c == 'p')
        length = p_specifier((void *)va_arg(args, void *));
    if (c == 'd' || c == 'i')
        length = di_specifier((int)va_arg(args, int));
    if (c == 'u')
        write(1, "u", 1);
    if (c == 'x')
        write(1, "x", 1);
    if (c == 'X')
        write(1, "X", 1);
    if (c == '%')
    {
        length++;
        write(1, &(char){'%'}, 1);
    }
    return (length);
}

int ft_printf(const char *format, ...)
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
            write(1, &format[index], 1);
            length++;
        }
        index++;
    }
    return (length);
}

/*int main(void)
{
    // int x = 42;
    int ori, meu;

    // meu = ft_printf("MEU: %d\n", -2147483648);
    // ori = printf("ORI: %d\n", 2147483647);

    meu = ft_printf(" NULL %s NULL ", NULL);
    ori = printf(" NULL %s NULL ", NULL);
    printf("retornos: meu:%d e ori:%d\n", meu, ori);
    return 0;
}*/