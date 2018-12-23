/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pushback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 04:50:27 by tduval            #+#    #+#             */
/*   Updated: 2018/12/06 09:32:22 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_list	*lst_pushback(t_list *lst, int num)
{
	t_list	*top;
	t_list	*elem;

	top = lst;
	if (lst)
	{
		if (!(elem = lst_new(num)))
			return (0);
		while (lst->next)
			lst = lst->next;
		lst->next = elem;
	}
	return (top);
}
