/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:33:16 by rgu               #+#    #+#             */
/*   Updated: 2025/04/30 00:45:09 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*temp;

	if (!stack)
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

void	push_swap(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = init_stack(argc, argv);
	if (!a)
		return ;
	if (check_is_sorted(a) == 1)
	{
		free_stack(a);
		return ;
	}
	b = create_stack();
	if (!b)
	{
		free_stack (a);
		return ;
	}
	if (a->size <= 5)
		sort_small(a, b);
	else
		sort_big(a, b);
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
	if (check_is_valid(argc, argv) == 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	push_swap(argc, argv);
	return (0);
}
