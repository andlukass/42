/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:32:56 by user              #+#    #+#             */
/*   Updated: 2023/08/26 09:10:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_unique(int *array, int length)
{
	int	index;
	int	j;

	index = 0;
	while(index < length)
	{
		j = -1;
		while(++j < length)
			if(array[j] == array[index] && j != index)
				return(ERROR);
		index++;
	}
	return (OK);
}

int	valid_number(char *arg)
{
	int index;
	long int value;

	index = -1;
	while(arg[++index])
	{
		if (!is_number(arg[index]))
		{	
			if(((arg[0] == '+' || arg[0] == '-') && (arg[1] || arg[1] == ' ') 
				&& index++ == 0) || arg[index] == ' ')
				continue ;
			return (ERROR);
		}
	}
	if	(index > 11)
		return (ERROR);
	value = ft_atoi(arg);
	if	(value > 2147483647 || value < -2147483648)
		return (ERROR);
	return (OK);
}

void	get_indexes(int *array, int length)
{
	int	copy[length];
	int	index;
	int	j;

	index = -1;
	while (++index < length)
		copy[index] = array[index];
	bubble_sort(copy, length);
	index = -1;
	while (++index < length)
	{
		j = -1;
		while (++j < length)
		{
			if (array[index] == copy[j])
			{
				array[index] = j;
				break;
			}
		}
	}
	index = 0;
	while(index < length)
		index++;
}
int	atolarize(int *array, int length, char *arguments[])
{
	int	index;
	int	value;
	int	size;

	index = 0;
	while(index < length)
	{
		if (!valid_number(arguments[index]))
			return (ERROR);
		value = ft_atoi(arguments[index]);
		array[index] = value;
		index++;
	}
	if (!is_unique(array, length))
		return (ERROR);
	return (OK);
}

int	init_stacks(t_data *data, int length, char *arguments[])
{
	int index;
	int array[length];
	long int value;

	index = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
	data->a_len = length;
	data->b_len = 0;
	if (!atolarize(array, length, arguments))
		return (ERROR);
	get_indexes(array, length);
	while (index < length)
		add_to_stack_last(&data->stack_a, new_stack_value(array[index++]));
	return (OK);
}

void	print_stack(t_stack *stack)
{
	while(stack)
	{
		printf("%d\n", stack->value);
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

int contarCaractere(const char *string, char caractere) {
	int contador = 0;
	const char *ptr = string;

	while ((ptr = strchr(ptr, caractere)) != NULL) {
		contador++;
		ptr++; // Avança para a próxima posição na string
	}
	return contador;
}

int	count_words(char *str)
{
	int	index;
	int	words;

	index = 0;
	words = 0;
	while(str[index])
	{
		if(str[index] != ' ' && (str[index + 1] == ' ' || str[index + 1] == '\0'))
			words++;
		index++;
	}
	return (words);
}

int	arg_count(int argc, char *argv[])
{
	int	index;
	int	spaces;
	int	length;

	index = 1;
	length = 0;
	while(index < argc)
	{
		spaces = contarCaractere(argv[index], ' ');
		if(spaces)
			length = length + count_words(argv[index]);
		else
			length++;
		index++;
	}
	return (length);
}

int	get_sub_args(char *arguments[], char *argv[], int *index, int *j)
{
	int	spaces;
	int	init;
	int	k;

	k = 0;
	spaces = contarCaractere(argv[*index], ' ');
	while (spaces)
	{
		while(argv[*index][k] == ' ')
			k++;
		init = k;
		while(argv[*index][k] != ' ' && argv[*index][k] != '\0')
			k++;
		spaces = contarCaractere(&argv[*index][k], ' ');
		if (!argv[*index][k] && argv[*index][k - 1] == ' ')
			continue ;
		arguments[*j] = ft_strdup(&argv[*index][init], k - init);
		*j = *j + 1;
	}
	return (k);
}

void	get_args(int argc, char *argv[], char *arguments[])
{
	int	index;
	int	j;
	int	k;

	index = 1;
	j = 0;
	while(index < argc)
	{
		if (get_sub_args(arguments, argv, &index, &j))
			index++;
		if (index >= argc)
			break ;
		arguments[j] = ft_strdup(argv[index], strlen(argv[index]));
		j++;
		index++;
	}
}

char	**handle_args(int argc, char *argv[], int *length)
{
	char	**arguments;

	*length = arg_count(argc, argv);
	arguments = malloc(sizeof(char *) * *length);
	get_args(argc, argv, arguments);
	return (arguments);
}

void printteste(char **arguments, int length)
{
	int index = 0;

	printf("len: %d\n", length);
	while(index < length)
	{
		printf("arg: %s\n", arguments[index]);
		index++;
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char	**arguments;
	int		length;

	if (argc == 0)
		return (0);
	arguments = handle_args(argc, argv, &length);
	if (!init_stacks(&data, length, arguments))
		return (write(1, "error\n", 6));
	if(length <= 5)
		sort_little(&data);
	else
		sort_large(&data);
	// free(arguments);
	// print_stacks(data);
}
