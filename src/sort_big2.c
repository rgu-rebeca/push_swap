#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	return ;
}

int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	i = low;
	j = low;
	pivot = arr[high];
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap(&arr[i], &arr[high]);
	return (i);
}

void	quick_sort(int arr[], int low, int high)
{
	int	partition_index;

	if (low < high)
	{
		partition_index = partition(arr, low, high);
		quick_sort(arr, low, partition_index - 1);
		quick_sort(arr, partition_index + 1, high);
	}
}

void	copy_and_sort(int *arr, int *sorted, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		sorted[i] = arr[i];
		i++;
	}
	quick_sort(sorted, 0, size - 1);
}

void	normalize_stack(t_stack *a, int *sorted)
{
	int		j;
	t_node	*node;

	j = 0;
	node = a->top;
	while (node)
	{
		j = 0;
		while (j < a->size)
		{
			if (node->value == sorted[j])
			{
				node->value = j;
				break ;
			}
			j++;
		}
		node = node->next;
	}
}
