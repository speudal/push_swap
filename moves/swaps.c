/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:41:18 by tduval            #+#    #+#             */
/*   Updated: 2019/01/05 16:27:27 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	sa(t_list **stack_a, int u)
{
	if (*stack_a && (*stack_a)->next)
	{
		if (u)
			ft_putstr("sa\n");
		ft_swap(&(*stack_a)->n, &(*stack_a)->next->n);
	}
}

void	sb(t_list **stack_b, int u)
{
	if (*stack_b && (*stack_b)->next)
	{
		if (u)
			ft_putstr("sb\n");
		ft_swap(&(*stack_b)->n, &(*stack_b)->next->n);
	}
}

void	ss(t_list *stack_a, t_list *stack_b, int u)
{
	if (u)
		ft_putstr("ss\n");
	sa(&stack_a, 0);
	sb(&stack_b, 0);
}
