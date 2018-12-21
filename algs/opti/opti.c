/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:53:50 by tduval            #+#    #+#             */
/*   Updated: 2018/12/21 17:38:04 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int		get_med(t_list *stack)
{
	int		i;
	int		len;

	i = 0;
	len = 1;
	if (stack)
	{
		len = lst_len(stack);
		while (stack)
		{
			i += stack->n;
			stack = stack->next;
		}
	}
	return (i / len);
}

static int		is_largest(t_list *stack)
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

int	is_smallest(t_list *stack)
{
	int		l;

	l = 0;
	if (stack)
	{
		l = stack->n;
		while (stack)
		{
			if (stack->n < l)
				l = stack->n;
			stack = stack->next;
		}
	}
	return (l);
}

static int	get_ind(t_list *stack, int j)
{
	int		i;

	i = 0;
	while (stack->n != j)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void			opti_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	k = 0;
	while (*stack_a && stacks_sorted(*stack_a) != 2)
	{
		j = 0;
		len = lst_len(*stack_a);
		i = k > 2 ? get_med(*stack_a) : get_med(*stack_a) / 2;
		while (j < len)
		{
			if ((*stack_a)->n <= i)
				pb(stack_a, stack_b, 1);
			else if ((*stack_a)->next && (*stack_a)->next->n <= i)
			{
				sa(stack_a, 1);
				pb (stack_a, stack_b, 1);
			}
			else
				ra(stack_a, 1);
			j++;
		}
		k++;
	}
	while (*stack_b)
	{
		if (is_largest(*stack_b) == (*stack_b)->n)
		{
			pa(stack_a, stack_b, 1);
			rrb(stack_b, 1);
		}
		else
		{
			while (is_largest(*stack_b) != (*stack_b)->n)
			{
				if (get_ind(*stack_b, is_largest(*stack_b)) > lst_len(*stack_b) / 2)
					rrb(stack_b, 1);
				else
					rb(stack_b, 1);
			}
		}
	}
}
