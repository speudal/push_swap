/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:48:28 by tduval            #+#    #+#             */
/*   Updated: 2018/12/06 08:12:34 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	pa(t_list **stack_a, t_list **stack_b, int u)
{
	t_list	*cp;

	if (u)
		ft_putstr("pa\n");
	if (stack_b)
	{
		cp = *stack_b;
		*stack_b = (*stack_b)->next;
		cp->next = *stack_a;
		*stack_a = cp;
	}
}

void	pb(t_list **stack_a, t_list **stack_b, int u)
{
	t_list	*cp;
	
	if (u)
		ft_putstr("pb\n");
	if (stack_a)
	{
		cp = *stack_a;
		*stack_a = (*stack_a)->next;
		cp->next = *stack_b;
		*stack_b = cp;
	}
}
