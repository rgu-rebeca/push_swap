#include "../include/push_swap.h"
#include "../libft/libft.h"

static long	ft_strtol(const char *str, char **endptr, int base)
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
		if (num > INT_MAX)
			return (sign * INT_MIN);
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (num * sign);
}

static int	check_is_int_range(char *str)
{
	long	num;
	char	*end_ptr;

	num = ft_strtol(str, &end_ptr, 10);
	if (*end_ptr != '\0')
		return (0);
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

int	check_is_valid(int argc, char **argv)
{
	char	**numbers;
	int		count;

	count = 0;
	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		if (!numbers)
			return (0);
		while (numbers[count])
			count++;
	}
	else
	{
		count = argc - 1;
		numbers = argv;
	}
	while (count >= 1)
	{
		if (!check_is_int(numbers[count])
			|| !check_is_int_range(numbers[count]))
			return (0);
		count--;
	}
	return (check_duplicate(count, numbers));
}
