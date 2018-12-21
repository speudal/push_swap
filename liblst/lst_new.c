/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 03:51:46 by tduval            #+#    #+#             */
/*   Updated: 2018/12/06 04:09:25 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_list	*lst_new(int num)
{
	t_list	*lst;

	if (!(lst = (t_list *)malloc(sizeof(t_list))))
		return (0);
	lst->n = num;
	lst->next = 0;
	return (lst);
}
