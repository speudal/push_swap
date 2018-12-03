/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 00:51:59 by tduval            #+#    #+#             */
/*   Updated: 2018/12/03 02:00:30 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rra(int **stacks)
{
	int	i;
	int	t;

	i = stacks[0][0];
	ft_printf("rra\n");
	while (i > 1)
	{
		ft_swap(&stacks[0][i], &stacks[0][i - 1]);
		i--;
	}
}

void	rrb(int **stacks)
{
	int	i;
	int	t;

	ft_printf("rrb\n");
	i = stacks[1][0];
	while (i > 1)
	{
		ft_swap(&stacks[1][i], &stacks[1][i - 1]);
		i--;
	}
}

void	rrr(int **stacks)
{
	rra(stacks);
	rrb(stacks);
}
