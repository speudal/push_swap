/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:21:46 by tduval            #+#    #+#             */
/*   Updated: 2018/11/30 21:29:26 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_u(va_list ap, t_flags elem)
{
	unsigned int	n;
	unsigned int	cp;
	int				i;

	i = 1;
	n = va_arg(ap, unsigned int);
	cp = n;
	while (cp > 9)
	{
		cp /= 10;
		i++;
	}
	return (n == 0 && elem.accuracy == 0 ?
	padding_u((unsigned long long)n, 0, elem) : i +
	padding_u((unsigned long long)n, i, elem));
}
