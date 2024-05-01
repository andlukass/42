/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 16:04:52 by llopes-d          #+#    #+#             */
/*   Updated: 2023/05/29 14:19:29 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define L_HEX "0123456789abcdef"
# define U_HEX "0123456789ABCDEF"

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

char	*ft_strchr(const char *s, int c);

int		ft_putstr_base(char *base, long int index,
			unsigned long int *nbr_final);

int		ft_get_length(long int i);

int		ft_putstr_len(char *str);

int		xx_specifier(unsigned int nbr, char c);

int		u_specifier(unsigned int nb);

int		p_specifier(void *adress);

int		s_specifier(char *str);

int		di_specifier(int nb);

int		c_specifier(char c);

int		ft_printf(const char *format, ...);

#endif
