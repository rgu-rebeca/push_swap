/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:43:11 by rgu               #+#    #+#             */
/*   Updated: 2025/04/30 01:02:27 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node		*top;
	int			size;
}	t_stack;

t_stack	*init_stack(int argc, char **argv);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *a);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);
t_stack	*init_stack(int argc, char **argv);
void	push_swap(int argc, char **argv);
void	sort_big(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b);
int		check_is_sorted(t_stack *a);
void	free_stack(t_stack *stack);
t_stack	*create_stack(void);
int		check_is_valid(int argc, char **argv);
int		main(int argc, char **argv);
void	swap(int *a, int *b);
int		partition(int arr[], int low, int high);
void	quick_sort(int arr[], int low, int high);
void	copy_and_sort(int *arr, int *sorted, int size);
void	calculate_index(t_stack *a, int *sorted);
int		count_nodes_in_chunk(t_stack *a, int min, int max);
int		count_r(t_stack *stack, int target_index);
void	k_sort1(t_stack *a, t_stack *b);
void	k_sort2(t_stack *a, t_stack *b);
int		ft_sqrt(int nb);
void	print_stack(t_stack *stack, const char *name);
void	free_memory(int i, char **numbers);
long	ft_strtol(const char *str, int base);
#endif