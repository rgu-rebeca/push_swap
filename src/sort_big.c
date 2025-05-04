/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:33:22 by rgu               #+#    #+#             */
/*   Updated: 2025/05/04 13:12:53 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	arr = malloc(sizeof(int) * size);
	sorted = malloc(sizeof(int) * size);
	if (!arr || !sorted)
		return ;
	while (node)
	{
		arr[i] = node->value;
		node = node->next;
		i++;
	}
	copy_and_sort(arr, sorted, size);
	calculate_index(a, sorted);
	free(arr);
	free(sorted);
}

void	big_sort1(t_stack *a, t_stack *b)
{
	int	i;
	int	range;
	int	size;

	size = a->size;
	i = 0;
	range = ft_sqrt(size) + 2;
	while (a->top)
	{
		if (a->top->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (a->top->index <= i + range)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

void	big_sort2(t_stack *a, t_stack *b)
{
	int	size;
	int	rb_count;
	int	rrb_count;

	size = b->size;
	while (size > 0)
	{
		rb_count = count_r(b, size - 1);
		rrb_count = size - rb_count;
		if (rb_count <= rrb_count)
		{
			while (b->top->index != size - 1)
				rb(b);
		}
		else
		{
			while (b->top->index != size - 1)
				rrb(b);
		}
		pa(a, b);
		size--;
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	preprocess_stack(a);
	big_sort1(a, b);
	big_sort2(a, b);
}
