/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:53:50 by tduval            #+#    #+#             */
/*   Updated: 2019/01/07 20:26:35 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static int		get_ind(t_list *stack, int j)
{
	int	i;

	i = 0;
	while (stack->n != j)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

static void		do_case2(t_list **stack_a, t_list **stack_b)
{
	int		l;

	l = lst_len(*stack_b);
	if (get_ind(*stack_b, is_largest(*stack_b) - 1) != 0)
		rrb (stack_b, 1);
	pa(stack_a, stack_b, 1);
	while ((*stack_b)->n != is_largest(*stack_b))
	{
		if (get_ind(*stack_b, is_largest(*stack_b)) < l / 2)
			rb(stack_b, 1);
		else
			rrb(stack_b, 1);
	}
	pa(stack_a, stack_b, 1);
	if ((*stack_b) && (*stack_b)->next && (*stack_b)->next->n > (*stack_b)->n)
		ss(*stack_a, *stack_b, 1);
	else
		sa(stack_a, 1);
}

static void		split(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		t;

	t = lst_len(*stack_a);
	i = get_med(*stack_a);
	while (t)
	{
		if ((*stack_a)->n <= i)
		{
			pb(stack_a, stack_b, 1);
			if ((*stack_b)->n < get_med(*stack_b) &&
					lst_len(*stack_b) > 1)
			{
				if ((*stack_a)->n > i)
					rr(stack_a, stack_b, 1);
				else
					rb(stack_b, 1);
			}
		}
		else
			ra(stack_a, 1);
		t--;
	}
}

void			opti_sort(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a)
		split(stack_a, stack_b);
	while (*stack_b)
	{
		if (is_largest(*stack_b) == (*stack_b)->n)
			pa(stack_a, stack_b, 1);
		else if ((*stack_b)->n == is_largest(*stack_b) - 1)
			do_case2(stack_a, stack_b);
		else
		{
			while (is_largest(*stack_b) != (*stack_b)->n &&
					(*stack_b)->n != is_largest(*stack_b) - 1)
			{
				if (get_ind(*stack_b, is_largest(*stack_b))
						> lst_len(*stack_b) / 2)
					rrb(stack_b, 1);
				else
					rb(stack_b, 1);
			}
		}
	}
}
