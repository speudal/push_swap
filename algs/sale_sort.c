/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sale_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 01:35:05 by tduval            #+#    #+#             */
/*   Updated: 2018/12/03 03:31:55 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sale_sort(int **stacks)
{
	int			tmp;
	int			i;
	int			j;

	while (stacks[0][0])
	{
		i = 1;
		tmp = 1;
		while (i < stacks[0][0] + 1)
		{
			if (stacks[0][i] > stacks[0][tmp])
				tmp = i;
			i++;
		}
		while (tmp > 1)
		{
			ra(stacks, 1);
			tmp--;
		}
		pb(stacks, 1);
	}
	i = 0;
	tmp = stacks[1][0];
	while (i < tmp)
	{
		rrb(stacks, 1);
		pa(stacks, 1);
		i++;
	}
}
