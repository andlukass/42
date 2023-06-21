/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:51:32 by llopes-d          #+#    #+#             */
/*   Updated: 2023/06/21 20:03:33 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define DIGITS "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <stdlib.h>

int		ft_atoi_base(char *s, int base);

int		ft_strlen(const char *s);

char	*ft_itoa(int n);

#endif
