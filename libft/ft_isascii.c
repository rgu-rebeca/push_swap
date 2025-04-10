/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:59:30 by ruijia            #+#    #+#             */
/*   Updated: 2025/02/27 22:53:55 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int a)
{
	if (0 <= a && a <= 127)
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	char	a;

	a = 'a';
	if (ft_isascii(a) == 1)
		write(1, "ok", 2);
	else
		write(1, "no", 2);
}*/
