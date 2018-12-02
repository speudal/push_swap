/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:34:42 by tduval            #+#    #+#             */
/*   Updated: 2018/12/02 19:37:42 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"

int		check_stack(int *stack, int c)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	while (i < c)
	{
		j = i + 1;
		while (j < c)
		{
			if (stack[j] == stack[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		*cat_params(int ac, char **av, int *c)
{
	int		*stack;
	int		*check;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (!av[i][j])
			return (0);
		while (av[i][j])
		{
			if (av[i][j] != ' ' && j)
				return (0);
			while (av[i][j] == ' ' && av[i][j])
				j++;
			if (ft_isdigit(av[i][j]) || av[i][j] == '+' || av[i][j] == '-')
			{
				if (av[i][j] == '-' || av[i][j] == '+')
				{
					j++;
					if (ft_isdigit(av[i][j]) == 0 || av[i][j] == 0)
						return (0);
				}
				if (ft_atoi(av[i] + j) > 0 && av[i][j - 1] == '-')
					return (0);
				else if (ft_atoi(av[i] + j) < 0 && av[i][j - 1] != '-')
					return (0);
				while ((ft_isdigit(av[i][j])) && av[i][j])
					j++;
				(*c)++;
			}
			else 
				return (0);
		}
		i++;
	}
	if (!(stack = (int *)malloc(sizeof(int) * (*c))))
		return (0);
	i = 1;
	*c = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ' && av[i][j])
				j++;
			stack[*c] = ft_atoi(av[i] + j);
			while ((ft_isdigit(av[i][j]) || av[i][j] == '-' || av[i][j] == '+' ) && av[i][j])
				j++;
			(*c)++;
		}
		i++;
	}
	if (check_stack(stack, *c) == 0)
		return (0);
	return (stack);
}

void	print_stack(int *stack, int c)
{
	int		i;

	i = 0;
	while (i < c)
	{
		ft_printf("%d\n", stack[i]);
		i++;
	}
}

int		main(int ac, char **av)
{
	int		*stack;
	int		c;

	c = 0;
	stack = 0;
	if (!(stack = cat_params(ac, av, &c)) || ac < 2)
	{
		ft_printf("Error\n");
		if (stack)
			free(stack);
		return (0);
	}
	print_stack(stack, c);
	free(stack);
	return (0);
}
