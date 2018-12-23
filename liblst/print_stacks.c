/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 08:30:22 by tduval            #+#    #+#             */
/*   Updated: 2018/12/20 00:13:23 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	ft_printf("STACK A :\t\t\tSTACK B :\n\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
			ft_printf("%d", stack_a->n);
		ft_putstr("\t\t\t");
		if (stack_b)
			ft_printf("%d\t\t\t", stack_b->n);
		ft_putchar('\n');
		if (stack_a)
			stack_a = stack_a->next;
		if (stack_b)
			stack_b = stack_b->next;
	}
}
