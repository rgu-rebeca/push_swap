#include "../include/push_swap.h"

#include <stdio.h>

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	a->top = second;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	if (!b)
		return ;
	first = b->top;
	second = b->top->next;
	first->next = second->next;
	second->next = first;
	b->top = second;
	write(1, "sb\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*first_b;

	if (!b || !b->top)
		return ;
	first_b = b->top;
	b->top = first_b->next;
	b->size--;
	first_b->next = a->top;
	a->top = first_b;
	a->size++;
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*first_a;

	if (!a || !a->top)
		return ;
	first_a = a->top;
	a->top = first_a->next;
	a->size--;
	first_a->next = b->top;
	b->top = first_a;
	b->size++;
	write(1, "pb\n", 3);
}
/*void	print_stack(t_stack *b, char *str)
{
	t_node *current = b->top;

	printf("%s", str);
	while (current)
	{
		printf("%d->", current->value);
		current = current->next;
	}
	printf("NULL");
	return;
}

int main()
{
    t_stack *b = init_stack(4, (char *[]){"", "9", "8", "7", "6"});

    print_stack(b, "Antes de sb");
    sb(b);
    print_stack(b, "Después de sb");

    return 0;
}*/