#include "../include/push_swap.h"
#include "../libft/libft.h"

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
