/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:32:50 by rgu               #+#    #+#             */
/*   Updated: 2025/05/03 18:47:20 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static void	push(t_stack *stack, int num)
{
	t_node	*new_node;
	t_node	*current;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = num;
	new_node->next = NULL;
	if (!stack->top)
		stack->top = new_node;
	else
	{
		current = stack->top;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	stack->size++;
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack -> top = NULL;
	stack -> size = 0;
	return (stack);
}

t_stack	*init_stack_aux(char **argv, t_stack *a)
{
	char	**numbers;
	int		i;
	int		num;

	numbers = ft_split(argv[1], ' ');
	if (!numbers)
	{
		if (a)
			free_stack(a);
		return (NULL);
	}
	i = 0;
	while (numbers[i])
	{
		num = ft_atoi(numbers[i]);
		push(a, num);
		free(numbers[i]);
		i++;
	}
	free(numbers);
	return (a);
}

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		num;

	a = create_stack();
	if (argc == 2)
		init_stack_aux(argv, a);
	else
	{
		i = 1;
		while (i < argc)
		{
			num = ft_atoi(argv[i]);
			push(a, num);
			i++;
		}
	}
	return (a);
}
