/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:21:30 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/30 19:13:47 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convertion(char c, va_list args)
{
	int	length;

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
		length = u_specifier((unsigned int)va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		length = xx_specifier((long int)va_arg(args, long int), c);
	if (c == '%')
	{
		length++;
		write(1, &c, 1);
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		index;
	int		length;

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
