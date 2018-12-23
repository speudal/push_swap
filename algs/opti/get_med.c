/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_med.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:09:24 by tduval            #+#    #+#             */
/*   Updated: 2018/12/22 18:27:06 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static int	*get_cpy(t_list *stack)
{
	int		*tab;
	int		i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * lst_len(stack))))
		return (0);
	while (stack)
	{
		tab[i] = stack->n;
		stack = stack->next;
		i++;
	}
	return (tab);
}

static int	partition(int *arr, int low, int high) 
{ 
	int piv;
	int i;

	i = (low - 1);
	piv = arr[high];
	for (int j = low; j <= high- 1; j++) 
	{ 
		if (arr[j] <= piv) 
		{ 
			i++;
			ft_swap(&arr[i], &arr[j]); 
		} 
	} 
	ft_swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

static void	quick_sort(int *arr, int low, int high) 
{
	int		piv;

	if (low < high) 
	{ 
		piv = partition(arr, low, high); 
			quick_sort(arr, low, piv - 1); 
		quick_sort(arr, piv + 1, high); 
	} 
}

int			get_med(t_list *stack)
{
	int		*tab;
	int		res;
	int		i;

	i = 0;
	if (!(tab = get_cpy(stack)))
		return (0);
	quick_sort(tab, 0, lst_len(stack) - 1);
	i = 0;
	while (i < lst_len(stack) / 2)
		i++;
	res = tab[i];
	free(tab);
	return (res);
}
