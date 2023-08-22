#include "push_swap.h"

int	valid_arg(char *arg)
{
	int index;
	long int value;

	index = 0;
	while(arg[index])
	{
		if (!is_number(arg[index]))
		{	
			if((arg[0] == '+' || arg[0] == '-') && index++ == 0)
				continue ;
			return (ERROR);
		}
		index++;
	}
	if	(index > 11)
		return (ERROR);
	value = ft_atoi(arg);
	if	(value > 2147483647 || value < -2147483648)
		return (ERROR);
	return (OK);
}

int	*get_indexes(int *stack, int length)
{
	int	array[length];
	int	*ori;
	int	index;

	ori = malloc(sizeof(stack[0]) * length);
	index = 0;
	for (int i = 0; i < length - 1; ++i) {
	ori[i] = stack[i];
    array[i] = stack[i];
	}
	    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < length; ++j) {
            if (ori[i] == array[j]) {
                ori[i] = j;
                break;
            }
        }
    }
	return ori;
}

int	init_stacks(t_data *data, int argc, char *argv[])
{
	int index;
	int array[argc - 1];
	int *final;
	long int value;


	index = 1; // PRIMEIRO ARGUMENTO É O PROGRAMA
	data->stack_a = NULL;
	data->stack_b = NULL;
	while(index < argc)
	{
		if (!valid_arg(argv[index]))
			return (ERROR);
		value = ft_atoi(argv[index]);
		array[index - 1] = value;
		add_to_stack_last(&data->stack_a, new_stack_value(value));
		index++;
	}
	final = get_indexes(array, argc - 1);
	for (int i = 0; i < argc - 1; ++i) {
    	printf("%d ", final[i]);
    }
	free(final);
	//get_indexes(data->stack_a, stack_len(data->stack_a));
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
	printf("stack len: %d\n",stack_len(data.stack_a));
	print_stack(data.stack_a);
	printf("----------------\n");
	printf("stack b\n");
	printf("stack len: %d\n",stack_len(data.stack_b));
	print_stack(data.stack_b);
}

int	main(int argc, char *argv[])
{
	t_data data;

	if (argc == 0)
		return (0);
	if (!init_stacks(&data, argc, argv))
		return (write(1, "error\n", 6));

	print_stacks(data);
}