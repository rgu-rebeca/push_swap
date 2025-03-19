#include "../include/push_swap.h"
#include "../libft/libft.h"

/*static int	*lst_to_arr(t_stack *stack)
{
	t_node	*node;
	int		size;
	int		*arr;
	int		t;

	if (!stack || !stack->top)
	size = stack->size;
	node = stack->top;
	t = 0;
	arr = (int *)malloc(sizeof(int) * size);
	if(!arr)
		return (NULL);
	while(t < size)
	{
		arr[t++] = node->value;
		node = node->next;
	}
	return (arr);
}*/

int	check_is_sorted(t_stack *a)
{
	t_node	*node;

	if (!a || !a->top)
		return (1);
	node = a->top;
	while (node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	if (!stack || !stack->top)
		return ;
	node = stack->top;
	while (node)
	{
		temp = node->next;
		free(node);
		node = temp;
	}
	free(stack);
}
