/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:33:04 by rgu               #+#    #+#             */
/*   Updated: 2025/04/30 00:33:04 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *a)
{
	t_node	*last;
	t_node	*first;

	if (!a || a->size < 2 || !a->top)
		return ;
	last = a->top;
	while (last->next)
		last = last->next;
	first = a->top;
	a->top = first->next;
	last->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	t_node	*last;
	t_node	*first;

	if (!b || b->size < 2 || !b->top)
		return ;
	last = b->top;
	while (last->next)
		last = last->next;
	first = b->top;
	b->top = first->next;
	last->next = first;
	first->next = NULL;
	write(1, "rb\n", 3);
}

void	rra(t_stack *a)
{
	t_node	*penultimate;
	t_node	*last;

	if (!a || !a->top || !a->top->next)
		return ;
	last = a->top;
	penultimate = NULL;
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	last->next = a->top;
	a->top = last;
	penultimate->next = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	t_node	*penultimate;
	t_node	*last;

	if (!b || !b->top || !b->top->next)
		return ;
	last = b->top;
	penultimate = NULL;
	while (last->next)
	{
		penultimate = last;
		last = last->next;
	}
	last->next = b->top;
	b->top = last;
	penultimate->next = NULL;
	write(1, "rrb\n", 4);
}
/*static void add_front(t_stack *stack, int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if(!new_node)
		return ;
	new_node->value = num;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

t_stack *init_stack(int argc, char **argv) 
{
	t_stack	*stack;
	int		i;
	int		num;

	i = 1;
	stack = (t_stack*)malloc(sizeof(t_stack));
	if(!stack)
		return (NULL);
	stack -> top = NULL;
	stack -> size = 0;
	while (i < argc)
	{
		num = atoi(argv[i]);
		add_front(stack, num);
		i++;
	}
	return (stack);
}
void print_stack(t_stack *stack, char *name)
{
    printf("%s: ", name);
    t_node *current = stack->top;
    while (current)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    t_stack *a = init_stack(4, (char *[]){"", "1", "2", "3", "4"});

    print_stack(a, "Stack A antes de ra");
    ra(a);
    print_stack(a, "Stack A después de ra");

    return 0;
}*/
