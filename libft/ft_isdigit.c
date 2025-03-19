/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgu <rgu@student.42madrid.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:58:00 by ruijia            #+#    #+#             */
/*   Updated: 2025/03/02 20:04:39 by rgu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int a)
{
	if ('0' <= a && a <= '9')
		return (1);
	else
		return (0);
}

/*int	main(void)
{
	char	a;

	a = 'a';
	if (ft_isdigit(a) == 1)
		write(1, "ok", 2);
	else
		write(1, "no", 2);
}*/
