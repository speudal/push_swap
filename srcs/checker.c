/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:34:42 by tduval            #+#    #+#             */
/*   Updated: 2018/12/03 23:18:46 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

/*
static void	print_stacks(int **stacks, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 2)
	{
		j = 1;
		ft_printf("Pile %c :\n", 'A' + i);
		while (j < stacks[i][0] + 1)
		{
			ft_printf("%d\n", stacks[i][j]);
			j++;
		}
		i++;
		if (i == 1)
			ft_putchar('\n');
	}
	ft_putchar('\n');
}*/

static int	check_sorted(int **stacks)
{
	int	i;

	i = 1;
	while (i < stacks[0][0])
	{
		if (stacks[0][i] > stacks[0][i + 1])
			return (0);
		i++;
	}
	return (1);
}

static int	do_swap(char *line, int **stacks)
{
	if (!(ft_strcmp(line, "sa")))
		sa(stacks, 0);
	else if (!(ft_strcmp(line, "sb")))
		sb(stacks, 0);
	else if (!(ft_strcmp(line, "ss")))
		ss(stacks, 0);
	else if (!(ft_strcmp(line, "pa")))
		pa(stacks, 0);
	else if (!(ft_strcmp(line, "pb")))
		pb(stacks, 0);
	else if (!(ft_strcmp(line, "ra")))
		ra(stacks, 0);
	else if (!(ft_strcmp(line, "rb")))
		rb(stacks, 0);
	else if (!(ft_strcmp(line, "rr")))
		rr(stacks, 0);
	else if (!(ft_strcmp(line, "rra")))
		rra(stacks, 0);
	else if (!(ft_strcmp(line, "rrb")))
		rrb(stacks, 0);
	else if (!(ft_strcmp(line, "rrr")))
		rrr(stacks, 0);
	else
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	char		*line;
	int			**stacks;
	int			c;

	c = 0;
	stacks = 0;
	line = 0;
	if (!(stacks = cat_params(ac, av, &c)) || ac < 2)
	{
		ft_putstr("Error\n");
		free_all(stacks, 0);
		return (0);
	}
	while (get_next_line(0, &line))
	{
		if (!(do_swap(line, stacks)))
		{
			ft_putstr("Error\n");
			free_all(stacks, line);
			return (0);
		}
	}
	if (check_sorted(stacks))
	{
		ft_putstr("OK\n");
		return (0);
	}
	else
		ft_putstr("KO\n");
	free_all(stacks, line);
	return (0);
}
