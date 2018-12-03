/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 03:18:55 by tduval            #+#    #+#             */
/*   Updated: 2018/12/03 04:03:27 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int			main(int ac, char **av)
{
	int			**stacks;
	int			c;

	c = 0;
	stacks = 0;
	if (!(stacks = cat_params(ac, av, &c)) || ac < 2)
	{
		ft_putstr("Error\n");
		free_all(stacks, 0);
		return (0);
	}
	sale_sort(stacks);
	free_all(stacks, 0);
	return (0);
}
