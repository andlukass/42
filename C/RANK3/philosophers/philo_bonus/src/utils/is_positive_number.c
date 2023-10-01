/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_positive_number.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:26:44 by user              #+#    #+#             */
/*   Updated: 2023/09/29 17:04:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_positive_number(char *str)
{
	int		index;
	char	c;

	index = 0;
	if (!str[index])
		return (0);
	if (str[index] == '+')
		index++;
	while (str[index])
	{
		c = str[index];
		if ((c < '0' || c > '9'))
			return (0);
		index++;
	}
	return (1);
}
