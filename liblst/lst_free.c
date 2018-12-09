/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 08:03:10 by tduval            #+#    #+#             */
/*   Updated: 2018/12/09 04:14:54 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	lst_free(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (stack_a && *stack_a)
	{
		while (*stack_a)
		{
			tmp = *stack_a;
			(*stack_a) = (*stack_a)->next;
			free(tmp);
		}
	}
	if (stack_b && *stack_b)
	{
		while (*stack_b)
		{
			tmp = *stack_b;
			(*stack_b) = (*stack_b)->next;
			free(tmp);
		}
	}
}
