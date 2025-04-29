/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:33:38 by rgu               #+#    #+#             */
/*   Updated: 2025/04/30 01:02:40 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

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

int	count_r(t_stack *stack, int target_index)
{
	t_node	*head;
	int		count;

	head = stack->top;
	count = 0;
	while (head)
	{
		if (head->index == target_index)
			break ;
		count++;
		head = head->next;
	}
	return (count);
}

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (i * i <= nb)
		i++;
	return (i - 1);
}

void	free_memory(int i, char **numbers)
{
	int	a;

	a = 0;
	while (a < i)
		free(numbers[a++]);
	free(numbers);
}

long	ft_strtol(const char *str, int base)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * base + (*str - '0');
		str++;
	}
	return (num * sign);
}
