/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:41:18 by tduval            #+#    #+#             */
/*   Updated: 2018/12/06 09:17:05 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sa(t_list **stack_a, int u)
{
	t_list *cp;

	cp = 0;
	if (*stack_a && (*stack_a)->next)
	{
		if (u)
			ft_putstr("sa\n");
		cp = (*stack_a)->next;
		(*stack_a)->next = (*stack_a)->next->next;
		cp->next = *stack_a;
		*stack_a = cp;
	}
}

void	sb(t_list **stack_b, int u)
{
	t_list *cp;

	cp = 0;
	if (*stack_b && (*stack_b)->next)
	{
		if (u)
			ft_putstr("sa\n");
		cp = (*stack_b)->next;
		(*stack_b)->next = (*stack_b)->next->next;
		cp->next = *stack_b;
		*stack_b = cp;
	}
}

void	ss(t_list *stack_a, t_list *stack_b, int u)
{
	if (u)
		ft_putstr("ss\n");
	sa(&stack_a, 0);
	sb(&stack_b, 0);
}
