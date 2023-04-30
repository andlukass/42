/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:04:52 by llopes-d          #+#    #+#             */
/*   Updated: 2023/04/30 17:12:09 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

// # include "./specifiers/c_specifier.c"
// # include "./specifiers/s_specifier.c"
// # include "./specifiers/p_specifier.c"
// # include "./specifiers/di_specifier.c"
// # include "./specifiers/u_specifier.c"
// # include "./specifiers/xx_specifier.c"

int	c_specifier(char c);

int	s_specifier(char *str);

int	p_specifier(void *adress);

int	di_specifier(int nb);

int	u_specifier(unsigned int nb);

int	xx_specifier(unsigned int nbr, char c);

int	ft_printf(const char *format, ...);

#endif
