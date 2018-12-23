/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 03:58:59 by tduval            #+#    #+#             */
/*   Updated: 2018/12/06 05:52:22 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void		lst_print(t_list *lst)
{
	int		i;

	i = 1;
	if (lst)
	{
		while (lst)
		{
			ft_printf("Element number %d : %d\n", i, lst->n);
			i++;
			lst = lst->next;
		}
	}
}
