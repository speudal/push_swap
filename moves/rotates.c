/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 01:02:05 by tduval            #+#    #+#             */
/*   Updated: 2018/12/04 01:22:09 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ra(int **stacks, int u)
{
	int	i;

	if (u)
		ft_putstr("ra\n");
	i = 1;
	while (i < stacks[0][0])
	{
		ft_swap(&stacks[0][i], &stacks[0][i + 1]);
		i++;
	}
}

void	rb(int **stacks, int u)
{
	int	i;

	if (u)
		ft_putstr("rb\n");
	i = 1;
	while (i < stacks[1][0])
	{
		ft_swap(&stacks[1][i], &stacks[1][i + 1]);
		i++;
	}
}

void	rr(int **stacks, int u)
{
	if (u)
		ft_putstr("rr\n");
	ra(stacks, 0);
	rb(stacks, 0);
}
