/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 22:15:13 by tduval            #+#    #+#             */
/*   Updated: 2018/12/03 03:48:59 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft/libft.h"
#include "push_swap.h"

static int	check_stack(int *stack, int c)
{
	int i;
	int j;
	int tmp;

	i = 1;
	while (i < stack[0])
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

static int check_arg(char *avv, int *c)
{
	int j;

	j = 0;
	while (j < ft_strlen(avv))
	{
		if (avv[j] == '-' || avv[j] == '+' || ft_isdigit(avv[j]))
		{
			if (ft_atoi(avv + j) < -2147483648 || ft_atoi(avv + j) > 2147483647)
				return (0);
			if (avv[j] == '+' || avv[j] == '-')
				j++;
			while (j < ft_strlen(avv) && ft_isdigit(avv[j]))
				j++;
			(*c)++;
		}
		else if (avv[j])
			return (0);
		if (avv[j] && avv[j] != ' ')
			return (0);
		j++;
	}
	return (1);
}

static int check_args(int ac, char **av, int *c)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (!(av[i] = ft_strtrim(av[i])))
			return (0);
		if (!av[i][0])
			return (0);
		if (!(check_arg(av[i], c)))
			return (0);
		i++;
	}
return (1);
}

int		**cat_params(int ac, char **av, int *c)
{
	int	**stacks;
	int i;
	int j;

	stacks = 0;
	i = 1;
	if (!(check_args(ac, av, c)))
		return (0);
	if (!(stacks = (int **)malloc(sizeof(int *) * 2)))
		return (0);
	if (!(stacks[0] = (int *)malloc(sizeof(int) * (*c + 1))))
		return (0);
	if (!(stacks[1] = (int *)malloc(sizeof(int) * (*c + 1))))
		return (0);
	i = 1;
	stacks[0][0] = *c;
	stacks[1][0] = 0;
	*c = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ' && av[i][j])
				j++;
			stacks[0][*c] = ft_atoi(av[i] + j);
			while ((ft_isdigit(av[i][j]) || av[i][j] == '-' || av[i][j] == '+') && av[i][j])
				j++;
			(*c)++;
		}
		i++;
	}
	if (check_stack(stacks[0], *c) == 0)
	{
		free_all(stacks, 0);
		return (0);
	}
	return (stacks);
}
