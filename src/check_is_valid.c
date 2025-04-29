/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:32:44 by rgu               #+#    #+#             */
/*   Updated: 2025/04/30 01:04:13 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static int	check_is_int_range(char *str)
{
	long	num;

	num = ft_strtol(str, 10);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

static int	check_is_int(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_duplicate(int count, char **value)
{
	int	i;
	int	a;

	i = 0;
	while (i < count)
	{
		a = i + 1;
		while (a < count)
		{
			if (ft_atoi(value[i]) == ft_atoi(value[a]))
				return (0);
			a++;
		}
		i++;
	}
	return (1);
}

int	check_is_valid_aux(char **numbers)
{
	int	i;
	int	count;

	count = 0;
	while (numbers[count])
		count++;
	i = count;
	while (--count >= 0)
	{
		if (!check_is_int(numbers[count])
			|| !check_is_int_range(numbers[count]))
		{
			free_memory(i, numbers);
			return (0);
		}
	}
	if (check_duplicate(i, numbers) == 0)
	{
		free_memory(i, numbers);
		return (0);
	}
	free_memory(i, numbers);
	return (1);
}

int	check_is_valid(int argc, char **argv)
{
	char	**numbers;
	int		a;

	a = 0;
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
	{
		numbers = malloc((argc - 1) * sizeof(char *));
		if (!numbers)
			return (0);
		while (a < argc - 1)
		{
			numbers[a] = ft_strdup(argv[a + 1]);
			if (!numbers[a])
				return (free_memory(a, numbers), 0);
			a++;
		}
	}
	if (!numbers)
		return (0);
	if (!check_is_valid_aux(numbers))
		return (0);
	return (1);
}
