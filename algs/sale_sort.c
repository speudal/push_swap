/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sale_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:23:53 by tduval            #+#    #+#             */
/*   Updated: 2018/12/19 22:19:13 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	lst_at(t_list *stack, int u)
{
	int		i;

	i = 0;
	while (stack && stack->n != u)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

static void	split(t_list **stack_a, t_list **stack_b)
{
	t_list	*r;
	int		at;
	int		tmp;

	at = 0;
	r = *stack_a;
	tmp = (*stack_a)->n;
	while (*stack_a)
	{
		if ((*stack_a)->next && (*stack_a)->next->n < tmp)
			tmp = (*stack_a)->next->n;
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = r;
	if ((*stack_a)->next && (*stack_a)->n > (*stack_a)->next->n)
		sa(stack_a, 1);
	while ((*stack_a)->n != tmp)
		lst_at(*stack_a, tmp) < lst_len(*stack_a) / 2 ?
			ra(stack_a, 1) : rra(stack_a, 1);
	if (stacks_sorted(*stack_a) != 2)
		pb(stack_a, stack_b, 1);
}

void		sale_sort(t_list **stack_a, t_list **stack_b)
{
	while (*stack_a && stacks_sorted(*stack_a) != 2)
	{
		if ((*stack_a)->next && (*stack_a)->n > (*stack_a)->next->n)
			sa(stack_a, 1);
		if (stacks_sorted(*stack_a) != 2)
			split(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b, 1);
}
