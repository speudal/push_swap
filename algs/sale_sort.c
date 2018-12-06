/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sale_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:23:53 by tduval            #+#    #+#             */
/*   Updated: 2018/12/06 09:49:55 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int  stacks_sorted(t_list *stack)
{
	int f;

	f = -1;
	while (stack->next)
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

void	sale_sort(t_list **stack_a, t_list **stack_b)
{
	int			tmp;
	t_list		*r;

	while (*stack_a && stacks_sorted(*stack_a) != 2)
	{
		if ((*stack_a)->next && (*stack_a)->n > (*stack_a)->next->n)
			sa(stack_a, 1);
		if (stacks_sorted(*stack_a) != 2)
		{
			r = *stack_a;
			tmp = (*stack_a)->n;
			while (*stack_a)
			{
				if ((*stack_a)->next && (*stack_a)->next->n < tmp)
					tmp = (*stack_a)->next->n;
				(*stack_a) = (*stack_a)->next;
			}
			*stack_a = r;
			while ((*stack_a)->n != tmp)
				ra(stack_a, 1);
			pb(stack_a, stack_b, 1);
		}
	}
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
