/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:59:23 by ruijia            #+#    #+#             */
/*   Updated: 2025/03/02 20:04:30 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int a)
{
	if (('A' <= a && a <= 'Z') || ('a' <= a && a <= 'z'))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	char	a;

	a = '12';
	if (ft_isalpha(a) == 1)
		write(1, "ok", 2);
	else
		write(1, "no", 2);
}*/
