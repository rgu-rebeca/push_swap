#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
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
void	rb(t_stack *a);
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
void	normalize_stack(t_stack *a, int *sorted);
#endif