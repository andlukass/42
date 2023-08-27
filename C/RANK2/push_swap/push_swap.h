#if !defined PUSH_SWAP
# define PUSH_SWAP

# define OK 1
# define ERROR 0

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

typedef struct s_stack
{
	int value;
	struct s_stack *next;
} t_stack;

typedef struct s_data
{
	t_stack *stack_a;
	t_stack *stack_b;
	int		a_len;
	int		b_len;
} t_data;

//-----------MOVEMENTS--------------
//----SWAP
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
//----PUSH
void	pa(t_data *data);
void	pb(t_data *data);
//----ROTATE
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
//----REVERSE_ROTATE
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

//-------------STACK----------------
void	add_to_stack_first(t_stack **stack, t_stack *new);
void	add_to_stack_last(t_stack **stack, t_stack *new);
void	del_stack_first(t_stack **stack);
t_stack	*new_stack_value(int value);
int		stack_len(t_stack *stack);
void	print_stacks(t_data data);

//-------------SORT-----------------
void	sort_little(t_data *data);
void	sort_large(t_data *data);

//-------------UTILS----------------
char	*ft_strdup(char const *s1, int size);
void	bubble_sort(int *array, int length);
long int	ft_atoi(const char *str);
int		is_number(char number);

#endif // PUSH_SWAP
