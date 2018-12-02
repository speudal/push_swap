/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 16:34:42 by tduval            #+#    #+#             */
/*   Updated: 2018/12/02 22:51:33 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static void	print_stacks(int **stacks, int c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 2)
	{
		j = 0;
		ft_printf("Pile %c :\n", 'A' + i);
		while (j < c)
		{
			ft_printf("%d\n", stacks[i][j]);
			j++;
		}
		i++;
	}
}

void		free_all(int **stacks)
{
	if (stacks)
	{
		if (stacks[0])
			free(stacks[0]);
		if (stacks[1])
			free(stacks[1]);
		free(stacks);
	}
}

int			main(int ac, char **av)
{
	int		**stacks;
	int		c;

	c = 0;
	stacks = 0;
	if (!(stacks = cat_params(ac, av, &c)) || ac < 2)
	{
		ft_printf("Error\n");
		free_all(stacks);
		return (0);
	}
	print_stacks(stacks, c);
	free_all(stacks);
	return (0);
}
