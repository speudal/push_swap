/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:53:50 by tduval            #+#    #+#             */
/*   Updated: 2018/12/22 19:22:14 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

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

static int		is_case1(t_list *stack)
{
	if (is_largest(stack) == stack->n)
		return (1);
	return (0);
}

static int		is_case2(t_list *stack)
{
	int		i;

	i = 0;
	if (stack->n == is_largest(stack) - 1)
	{
		while (i < lst_len(stack) / 2)
		{
			if (is_largest(stack) == stack->n)
				return (1);
			stack = stack->next;
		}
	}
	return (0);
}

static void		do_case2(t_list **stack_a, t_list **stack_b)
{
	int		i;

	i = 0;
	pa (stack_a, stack_b, 1);
	while (!(is_case1(*stack_b)))
	{
		if (get_ind(*stack_b, is_largest(*stack_b)) > lst_len(*stack_b) / 2)
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
		i++;
	}
	pa(stack_a, stack_b, 1);
	while (i)
	{	rrb(stack_b, 1);
		i--;
	}
	sa(stack_a, 1);
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
		if (is_case1(*stack_b))
		{
			pa(stack_a, stack_b, 1);
			rrb(stack_b, 1);
		}
		else if (is_case2(*stack_b))
			do_case2(stack_a, stack_b);
		else
		{
			while (!(is_case1(*stack_b)) && !(is_case2(*stack_b)))
			{
				if (get_ind(*stack_b, is_largest(*stack_b)) > lst_len(*stack_b) / 2)
					rrb(stack_b, 1);
				else
					rb(stack_b, 1);
			}
		}
	}
}
