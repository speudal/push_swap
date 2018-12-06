/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 22:15:13 by tduval            #+#    #+#             */
/*   Updated: 2018/12/06 10:35:53 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft/libft.h"
#include "push_swap.h"

static int		check_stack(t_list *stack)
{
	t_list	*i;

	while (stack->next)
	{
		i = stack->next;
		while (i)
		{
			if (stack->n == i->n)
				return (0);
			i = i->next;
		}
		stack = stack->next;
	}
	return (1);
}

static int		check_arg(char *avv, int *c)
{
	int j;

	j = 0;
	while (j < (int)ft_strlen(avv))
	{
		if (avv[j] == '-' || avv[j] == '+' || ft_isdigit(avv[j]))
		{
			if (ft_atoi(avv + j) < -2147483648 || ft_atoi(avv + j) > 2147483647)
				return (0);
			if (avv[j] == '+' || avv[j] == '-')
				j++;
			while (j < (int)ft_strlen(avv) && ft_isdigit(avv[j]))
				j++;
			(*c)++;
		}
		else if (avv[j])
			return (0);
		if ((avv[j] && avv[j] != ' ') || (!avv[j + 1] && avv[j] == ' '))
			return (0);
		j++;
	}
	return (1);
}

static int		check_args(int ac, char **av, int *c)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (!av[i][0])
			return (0);
		if (!(check_arg(av[i], c)))
			return (0);
		i++;
	}
	return (1);
}

static void		fill_stack(int ac, char **av, t_list **stack_a)
{
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ' && av[i][j])
				j++;
			if (*stack_a)
				*stack_a = lst_pushback(*stack_a, ft_atoi(av[i] + j));
			else
				*stack_a = lst_new(ft_atoi(av[i] + j));
			while ((ft_isdigit(av[i][j]) || av[i][j] == '-'
						|| av[i][j] == '+') && av[i][j])
				j++;
		}
		i++;
	}
}

t_list			*cat_params(int ac, char **av, int *c)
{
	t_list	*stack_a;
	int		i;
	int		j;

	i = 1;
	j = 0;
	stack_a = 0;
	if (!(check_args(ac, av, c)))
		return (0);
	*c = 1;
	fill_stack(ac, av, &stack_a);
	if (check_stack(stack_a) == 0)
	{
		lst_free(&stack_a, 0);
		return (0);
	}
	return (stack_a);
}
