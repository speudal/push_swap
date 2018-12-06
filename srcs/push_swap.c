/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 03:18:55 by tduval            #+#    #+#             */
/*   Updated: 2018/12/06 09:56:18 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int			main(int ac, char **av)
{
	int			c;
	t_list		*stack_a;
	t_list		*stack_b;

	c = 0;
	if (ac < 2 || !(stack_a = cat_params(ac, av, &c)))
	{
		ft_putstr("Error\n");
		lst_free(&stack_a, &stack_b);
		return (0);
	}
	else
	{
		sale_sort(&stack_a, &stack_b);
		lst_free(&stack_a, &stack_b);
	}
	return (0);
}
