/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:39:28 by user              #+#    #+#             */
/*   Updated: 2023/08/26 14:58:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void decimalToBinary(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }

    int binary[32]; // Para armazenar os dígitos binários
    int i = 0;

    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

static void	print_stack(t_stack *stack)
{
	while(stack)
	{
		printf("%d ", stack->value);
		decimalToBinary( stack->value);
		printf("\n ");
		stack = stack->next;
	}
}

void	print_stacks(t_data data)
{
	printf("----------------\n");
	printf("stack a\n");
	printf("stack len: %d\n", data.a_len);
	print_stack(data.stack_a);
	printf("----------------\n");
	printf("stack b\n");
	printf("stack len: %d\n", data.b_len);
	print_stack(data.stack_b);
}