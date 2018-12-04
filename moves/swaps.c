/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:41:18 by tduval            #+#    #+#             */
/*   Updated: 2018/12/04 01:22:28 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sa(int **stacks, int u)
{
	if (stacks[0][0] > 1)
	{
		if (u)
			ft_putstr("sa\n");
		ft_swap(&stacks[0][1], &stacks[0][2]);
	}
}

void	sb(int **stacks, int u)
{
	if (stacks[1][0] > 1)
	{
		if (u)
			ft_putstr("sb\n");
		ft_swap(&stacks[1][1], &stacks[1][2]);
	}
}

void	ss(int **stacks, int u)
{
	if (u)
		ft_putstr("ss\n");
	sa(stacks, 0);
	sb(stacks, 0);
}
