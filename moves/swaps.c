/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:41:18 by tduval            #+#    #+#             */
/*   Updated: 2018/12/03 01:58:31 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sa(int **stacks)
{
	if (stacks[0][0] > 1)
	{
		ft_printf("sa\n");
		ft_swap(&stacks[0][1], &stacks[0][2]);
	}
}

void	sb(int **stacks)
{
	if (stacks[1][0] > 1)
	{
		ft_printf("sb\n");
		ft_swap(&stacks[1][1], &stacks[1][2]);
	}
}

void	ss(int **stacks)
{

	sa(stacks);
	sb(stacks);
}
