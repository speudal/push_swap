/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 01:02:05 by tduval            #+#    #+#             */
/*   Updated: 2018/12/03 01:57:31 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ra(int **stacks)
{
	int	i;
	int	t;

	ft_printf("ra\n");
	i = 1;
	while (i < stacks[0][0])
	{
		ft_swap(&stacks[0][i], &stacks[0][i + 1]);
		i++;
	}
}

void	rb(int **stacks)
{
	int	i;
	int	t;

	ft_printf("rb\n");
	i = 1;
	while (i < stacks[1][0])
	{
		ft_swap(&stacks[1][i], &stacks[1][i + 1]);
		i++;
	}
}

void	rr(int **stacks)
{
	ft_printf("rr\n");
	ra(stacks);
	rb(stacks);
}
