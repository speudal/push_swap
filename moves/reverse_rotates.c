/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 00:51:59 by tduval            #+#    #+#             */
/*   Updated: 2018/12/03 04:03:09 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rra(int **stacks, int u)
{
	int	i;
	int	t;

	i = stacks[0][0];
	if (u)
		ft_putstr("rra\n");
	while (i > 1)
	{
		ft_swap(&stacks[0][i], &stacks[0][i - 1]);
		i--;
	}
}

void	rrb(int **stacks, int u)
{
	int	i;
	int	t;

	if (u)
		ft_putstr("rrb\n");
	i = stacks[1][0];
	while (i > 1)
	{
		ft_swap(&stacks[1][i], &stacks[1][i - 1]);
		i--;
	}
}

void	rrr(int **stacks, int u)
{
	if (u)
		ft_putstr("rrr\n");
	rra(stacks, u);
	rrb(stacks, u);
}
