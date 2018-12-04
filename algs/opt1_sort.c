/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt1_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 23:19:57 by tduval            #+#    #+#             */
/*   Updated: 2018/12/04 01:14:59 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  stacks_sorted(int *stacks)
{
    int i;
    int f;

    i = 1;
    f = -1;
    while (i < stacks[0])
    {
        if (stacks[i] > stacks[i + 1])
        {
            if (f == -1)
                f = 1;
            else if (f == 2)
                return (0);
        }
        else
        {
            if (f == -1)
                f = 2;
            else if (f == 1)
                return (0);
        }       
        i++;
    }
    return (f);
}

void        opt1_sort(int **stacks)
{
    int i;
    int tmp;

    i = 1;
    while (stacks_sorted(stacks[0]) != 2)
    {
        while (stacks[0][i] < stacks[0][i + 1] && i < stacks[0][0])
            pb(stacks, 1);
        if (stacks[0][i] > stacks[0][i + 1] && i < stacks[0][0])
            sa(stacks, 1);
    } 
    while (stacks[1][0])
        pa(stacks, 1);
}