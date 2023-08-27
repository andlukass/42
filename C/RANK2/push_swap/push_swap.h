/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llopes-d <llopes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:33:27 by llopes-d          #+#    #+#             */
/*   Updated: 2023/08/27 17:46:28 by llopes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define OK 1
# define ERROR 0

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		a_len;
	int		b_len;
}	t_data;

//-----------MOVEMENTS--------------
//----SWAP
void		sa(t_data *data);
void		sb(t_data *data);
void		ss(t_data *data);
//----PUSH
void		pa(t_data *data);
void		pb(t_data *data);
//----ROTATE
void		ra(t_data *data);
void		rb(t_data *data);
void		rr(t_data *data);
//----REVERSE_ROTATE
void		rra(t_data *data);
void		rrb(t_data *data);
void		rrr(t_data *data);

//-----------ARGUMENTS--------------
char		**handle_args(int argc, char *argv[], int *length);
void		free_arguments(char **arguments);

//-------------STACK----------------
t_stack		*new_stack_value(int value);
int			init_stacks(t_data *data, int length, char *arguments[]);
int			stack_len(t_stack *stack);
void		add_to_stack_first(t_stack **stack, t_stack *new);
void		add_to_stack_last(t_stack **stack, t_stack *new);
void		del_stack_first(t_stack **stack);
void		free_stack(t_stack *stack);
void		print_stacks(t_data data);

//-------------SORT-----------------
void		sort_little(t_data *data);
void		sort_large(t_data *data);

//-------------UTILS----------------
void		bubble_sort(int *array, int length);
char		*ft_strdup(char const *s1, int size);
char		*ft_strchr(const char *s, int c);
int			count_char(char *str, char c);
int			count_words(char *str);
int			is_number(char number);
long int	ft_atoi(char *str);

#endif
