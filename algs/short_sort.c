/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 00:34:01 by tduval            #+#    #+#             */
/*   Updated: 2018/12/20 01:35:54 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	smallest(t_list *stack)
{
	int		i;

	i = 0;
	if (stack)
		i = stack->n;
	while (stack)
	{
		if (stack->n < i)
			i = stack->n;
		stack = stack->next;
	}
	return (i);
}

static int	get_index(t_list *stack, int i)
{
	int		j;

	j = 0;
	while (stack->n != i)
	{
		j++;
		stack = stack->next;
	}
	return (j);
}

static void	part_one(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->n != smallest(*stack_a))
	{
		if (get_index(*stack_a, smallest(*stack_a)) > 2)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
	pb(stack_a, stack_b, 1);
	if (lst_len(*stack_a) > 3)
	{
		while ((*stack_a)->n != smallest(*stack_a))
		{
			if (get_index(*stack_a, smallest(*stack_a)) > 2)
				rra(stack_a, 1);
			else
				ra(stack_a, 1);
		}
		pb(stack_a, stack_b, 1);
	}
}

void		short_sort(t_list **stack_a, t_list **stack_b)
{
	int		i;

	i = 0;
	if (lst_len(*stack_a) > 3)
		part_one(stack_a, stack_b);
	while (stacks_sorted(*stack_a) != 2)
	{
		if ((*stack_a)->n == smallest(*stack_a))
		{
			ra(stack_a, 1);
			sa(stack_a, 1);
			rra(stack_a, 1);
		}
		if ((*stack_a)->n > (*stack_a)->next->n)
			sa(stack_a, 1);
		if (*stack_a && (*stack_a)->next && (*stack_a)->next->next && (*stack_a)->next->next->n < (*stack_a)->n)
			rra(stack_a, 1);
	}
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
