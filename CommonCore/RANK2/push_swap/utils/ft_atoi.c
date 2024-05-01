/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:36:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/08/27 17:46:32 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atoi(char *str)
{
	long int	result;
	int			negative;
	int			i;

	result = 0;
	i = 0;
	negative = 1;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] == '-')
		negative *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		if (result == 0)
			result = str[i] - 48;
		else
			result = ((result * 10) + (str[i] - 48));
		i++;
	}
	return (result * negative);
}
