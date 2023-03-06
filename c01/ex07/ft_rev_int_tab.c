/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:31:36 by llopes-d          #+#    #+#             */
/*   Updated: 2023/03/06 18:31:38 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int	final;
	int	start;
	int	middle;
	int	buff;

	start = 0;
	middle = size / 2;
	final = size - 1;
	while (start <= middle)
	{
		buff = tab[start];
		tab[start] = tab[final];
		tab[final] = buff;
		final--;
		start++;
	}
}
