/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 19:32:07 by tduval            #+#    #+#             */
/*   Updated: 2018/11/09 16:54:28 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_sum(int *tab, size_t n)
{
	int	s;

	if (!tab)
		return (-1);
	s = 0;
	while (n--)
		s += tab[n];
	return (s);
}
