/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_popfront.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 04:41:09 by tduval            #+#    #+#             */
/*   Updated: 2018/12/06 04:56:21 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_list	*lst_popfront(t_list *lst)
{
	t_list	*prev;

	prev = lst;
	if (lst->next)
	{
		lst = lst->next;
		free(prev);
		prev = 0;
	}
	return (lst);
}
