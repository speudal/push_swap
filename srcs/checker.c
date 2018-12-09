/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:34:42 by tduval            #+#    #+#             */
/*   Updated: 2018/12/09 04:13:06 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static int	check_sorted(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (stack_a->n > stack_a->next->n)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

static int	do_swap(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!(ft_strcmp(line, "sa")))
		sa(stack_a, 0);
	else if (!(ft_strcmp(line, "sb")))
		sb(stack_b, 0);
	else if (!(ft_strcmp(line, "ss")))
		ss(*stack_a, *stack_b, 0);
	else if (!(ft_strcmp(line, "pa")))
		pa(stack_a, stack_b, 0);
	else if (!(ft_strcmp(line, "pb")))
		pb(stack_a, stack_b, 0);
	else if (!(ft_strcmp(line, "ra")))
		ra(stack_a, 0);
	else if (!(ft_strcmp(line, "rb")))
		rb(stack_b, 0);
	else if (!(ft_strcmp(line, "rr")))
		rr(*stack_a, *stack_b, 0);
	else if (!(ft_strcmp(line, "rra")))
		rra(stack_a, 0);
	else if (!(ft_strcmp(line, "rrb")))
		rrb(stack_b, 0);
	else if (!(ft_strcmp(line, "rrr")))
		rrr(*stack_a, *stack_b, 0);
	else
		return (0);
	return (1);
}

static int	solve_it(t_list *stack_a)
{
	t_list	*stack_b;
	char	*line;

	line = 0;
	while (get_next_line(0, &line))
	{
		if (!(do_swap(line, &stack_a, &stack_b)))
		{
			ft_putstr("Error\n");
			lst_free(&stack_a, &stack_b);
			return (0);
		}
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_list		*stack_a;
	t_list		*stack_b;
	int			c;

	c = 0;
	if (ac < 2 || !(stack_a = cat_params(ac, av, &c)))
	{
		if (ac > 1)
			ft_putstr("Error\n");
		lst_free(&stack_a, 0);
		return (0);
	}
	if (!(solve_it(stack_a)))
		return (0);
	if (check_sorted(stack_a))
	{
		ft_putstr("OK\n");
		return (0);
	}
	else
		ft_putstr("KO\n");
	lst_free(&stack_a, &stack_b);
	return (0);
}
