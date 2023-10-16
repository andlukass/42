/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_len_no_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:56:57 by user              #+#    #+#             */
/*   Updated: 2023/09/29 16:58:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	number_len_no_zero(char *str)
{
	int	len;
	int	index;

	index = 0;
	len = 0;
	while (str[index] == '+' || str[index] == '0')
		index++;
	while (str[index])
	{
		index++;
		len++;
	}
	return (len);
}
