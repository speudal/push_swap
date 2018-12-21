/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 07:35:27 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 14:11:54 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rra(t_list **stack_a, int u)
{
	t_list	*cp;
	t_list	*re;

	re = 0;
	cp = 0;
	if (u)
		ft_putstr("rra\n");
	if (*stack_a && (*stack_a)->next)
	{
		re = (*stack_a);
		while ((*stack_a)->next->next)
			*stack_a = (*stack_a)->next;
		cp = (*stack_a)->next;
		(*stack_a)->next->next = re;
		(*stack_a)->next = 0;
	}
	*stack_a = cp;
}

void	rrb(t_list **stack_b, int u)
{
	t_list	*cp;
	t_list	*re;

	re = 0;
	cp = 0;
	if (u)
		ft_putstr("rrb\n");
	if (*stack_b && (*stack_b)->next)
	{
		re = (*stack_b);
		while ((*stack_b)->next->next)
			*stack_b = (*stack_b)->next;
		cp = (*stack_b)->next;
		(*stack_b)->next->next = re;
		(*stack_b)->next = 0;
		*stack_b = cp;
	}
}

void	rrr(t_list *stack_a, t_list *stack_b, int u)
{
	if (u)
		ft_putstr("rrr\n");
	rra(&stack_a, 0);
	rrb(&stack_b, 0);
}
