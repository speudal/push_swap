/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 03:18:55 by tduval            #+#    #+#             */
/*   Updated: 2018/12/04 03:26:55 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void     print_stacks(int **stacks)
{
	int             i;
	int             j;

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
}

int			main(int ac, char **av)
{
	int			**stacks;
	int			c;

	c = 0;
	if (!(stacks = cat_params(ac, av, &c)) || ac < 2)
	{
		ft_putstr("Error\n");
		free_all(stacks, 0);
		return (0);
	}
	else
	{
		//opt1_sort(stacks);
		sale_sort(stacks);
		//print_stacks(stacks);
		free_all(stacks, 0);
	}
	return (0);
}
