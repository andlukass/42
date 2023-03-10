/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 20:58:06 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/06 20:58:09 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_int_tab(int *tab, int size)
{
	int	start;
	int	index;
	int	final;
	int	buff;

	start = 0;
	index = 0;
	final = size - 1;
	while (start < final)
	{
		index = 0;
		while (index < final)
		{
			if (tab[index] > tab[index + 1])
			{
				buff = tab[index];
				tab[index] = tab[index + 1];
				tab[index + 1] = buff;
			}
			index++;
		}
		start++;
	}
}
