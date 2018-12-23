/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_largest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:32:32 by tduval            #+#    #+#             */
/*   Updated: 2018/12/22 18:41:33 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_largest(t_list *stack)
{
	int		l;

	l = 0;
	if (stack)
	{
		l = stack->n;
		while (stack)
		{
			if (stack->n > l)
				l = stack->n;
			stack = stack->next;
		}
	}
	return (l);
}
