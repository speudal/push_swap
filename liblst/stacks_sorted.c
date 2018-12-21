/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 21:14:52 by tduval            #+#    #+#             */
/*   Updated: 2018/12/19 22:40:10 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stacks_sorted(t_list *stack)
{
	int f;

	f = -1;
	if (!stack)
		return (2);
	while (stack && stack->next)
	{
		if (stack->n > stack->next->n)
		{
			if (f == -1)
				f = 1;
			else if (f == 2)
				return (0);
		}
		else
		{
			if (f == -1)
				f = 2;
			else if (f == 1)
				return (0);
		}
		stack = stack->next;
	}
	return (f);
}
