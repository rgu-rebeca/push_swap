#include "../include/push_swap.h"

static void	sort_3(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	if (!a || !a->top || !a->top->next || !a->top->next->next)
		return ;
	first = a->top->value;
	second = a->top->next->value;
	third = a->top->next->next->value;
	if (first > second && second > third)
		(sa(a), rra(a));
	else if (first > second && first < third)
		sa(a);
	else if (first < third && second > third)
		(rra(a), sa(a));
	else if (third < first && first < second)
		rra(a);
	else if (second < third && third < first)
		(rra(a), rra(a));
}

static int	find_min_index(t_stack *a)
{
	int		min;
	int		i;
	int		min_index;
	t_node	*node;

	if (!a || !a->top)
		return (-1);
	node = a->top;
	min = node->value;
	min_index = 0;
	i = 0;
	while (node)
	{
		if (min > node->value)
		{
			min = node->value;
			min_index = i;
		}
		node = node->next;
		i++;
	}
	return (min_index);
}

static void	move_min_to_top(t_stack *a, int min_index)
{
	int	size;

	size = a->size;
	if (min_index < size / 2)
	{
		while (min_index > 0)
		{
			ra(a);
			min_index--;
		}
	}
	else if (min_index >= size / 2)
	{
		while (min_index < size)
		{
			rra(a);
			min_index++;
		}
	}
}

static void	sort_4_or_5(t_stack *a, t_stack *b)
{
	int	min_index;

	if (!a || !a->top || !b)
		return ;
	while (a->size > 3)
	{
		min_index = find_min_index(a);
		move_min_to_top(a, min_index);
		pb(a, b);
	}
	sort_3(a);
	while (b->size > 0)
		pa(a, b);
}

void	sort_small(t_stack *a, t_stack *b)
{
	int	size;

	size = a->size;
	if (size <= 1)
		return ;
	if (size == 2)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	if (size == 3)
		sort_3(a);
	if (size == 4 || size == 5)
		sort_4_or_5(a, b);
}

/*void	print_list(t_stack *stack)
{
	t_node	*node;

	node = stack->top;
	while(node)
	{
		printf("%d->", node->value);
		node = node->next;
	}
	printf("NULL");
	return ;
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	a = init_stack(4, (char*[]){"", "7", "9", "2", "5"});
	b = init_stack(0, (char*[]){""});
	printf("before sort, the stack is:\n");
	print_list(a);
	sort_small(a, b);
	printf("after sort, the stack is:\n");
	print_list(a);
}*/