/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:57:14 by ruijia            #+#    #+#             */
/*   Updated: 2025/03/02 20:10:04 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if (('0' <= a && a <= '9') || ('A' <= a && a <= 'Z')
		|| ('a' <= a && a <= 'z'))
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	char	a;

	a = '0';
	if (ft_isdigit(a) == 1)
		write(1, "ok", 2);
	else
		write(1, "no", 2);
}*/
