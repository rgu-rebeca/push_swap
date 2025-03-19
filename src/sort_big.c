#include "push_swap.h"

static void	preprocess_stack(t_stack *a)
{
	int		*arr;
	int		*sorted;
	int		size;
	t_node	*node;
	int		i;

	if (!a || !a->top)
		return ;
	size = a->size;
	node = a->top;
	i = 0;
	arr = (int *)malloc(sizeof(int) * size);
	sorted = (int *)malloc(sizeof(int) * size);
	if (!arr || !sorted)
		return ;
	while (node)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
	copy_and_sort(arr, sorted, size);
	normalize_stack(a, sorted);
	free(arr);
	free(sorted);
}

static void	radix_sort_aux(t_stack *a, int bit, int max_bits, t_stack *b)
{
	int	count;
	int	value;

	while (bit < max_bits)
	{
		count = a->size;
		while (count--)
		{
			value = a->top->value;
			if ((value >> bit) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (b->top)
			pa(a, b);
		bit++;
	}
}

static void	radix_sort(t_stack *a, t_stack *b)
{
	int	size;
	int	max_bits;
	int	bit;

	size = a->size;
	if (size == 0)
		return ;
	max_bits = 0;
	bit = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	radix_sort_aux(a, bit, max_bits, b);
}

void	sort_big(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	preprocess_stack(a);
	radix_sort (a, b);
}
