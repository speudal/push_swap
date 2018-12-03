/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:48:28 by tduval            #+#    #+#             */
/*   Updated: 2018/12/03 02:01:11 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pa(int **stacks)
{
	int	i;
	int	t;

	if (stacks[1][0] > 0)
	{
		i = 1;
		t = stacks[1][1];
		ft_printf("pa\n");
		stacks[1][0]--;
		stacks[0][0]++;
		while (i < stacks[1][0] + 1)
		{
			ft_swap(&stacks[1][i], &stacks[1][i + 1]);
			i++;
		}
		i = stacks[0][0] + 1;
		while (i > 1)
		{
			ft_swap(&stacks[0][i], &stacks[0][i - 1]);
			i--;
		}
		stacks[0][1] = t;
	}
}


void	pb(int **stacks)
{
	int	i;
	int	t;

	if (stacks[0][0] > 0)
	{
		i = 1;
		t = stacks[0][1];
		stacks[0][0]--;
		stacks[1][0]++;
		ft_printf("pb\n");
		while (i < stacks[0][0] + 1)
		{
			ft_swap(&stacks[0][i], &stacks[0][i + 1]);
			i++;
		}
		i = stacks[1][0] + 1;
		while (i > 1)
		{
			ft_swap(&stacks[1][i], &stacks[1][i - 1]);
			i--;
		}
		stacks[1][1] = t;
	}
}
