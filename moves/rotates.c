/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 07:35:07 by tduval            #+#    #+#             */
/*   Updated: 2019/01/07 18:38:17 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ra(t_list **stack_a, int u)
{
	t_list	*cp;
	t_list	*re;

	re = 0;
	if (u)
		ft_putstr("ra\n");
	if (*stack_a && (*stack_a)->next)
	{
		cp = *stack_a;
		re = (*stack_a)->next;
		while ((*stack_a)->next)
			*stack_a = (*stack_a)->next;
		(*stack_a)->next = cp;
		cp->next = 0;
		*stack_a = re;
	}
}

void	rb(t_list **stack_b, int u)
{
	t_list	*cp;
	t_list	*re;

	re = 0;
	if (u)
		ft_putstr("rb\n");
	if (*stack_b && (*stack_b)->next)
	{
		cp = *stack_b;
		re = (*stack_b)->next;
		while ((*stack_b)->next)
			*stack_b = (*stack_b)->next;
		(*stack_b)->next = cp;
		cp->next = 0;
		*stack_b = re;
	}
}

void	rr(t_list **stack_a, t_list **stack_b, int u)
{
	if (u)
		ft_putstr("rr\n");
	ra(stack_a, 0);
	rb(stack_b, 0);
}
