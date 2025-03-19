#include "../include/push_swap.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (1);
	if (check_is_valid(argc, argv) == 0)
	{
		write(2, "error\n", 6);
		return (1);
	}
	push_swap(argc, argv);
	return (0);
}
