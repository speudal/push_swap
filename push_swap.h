/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 22:24:26 by tduval            #+#    #+#             */
/*   Updated: 2018/12/03 03:36:41 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int			**cat_params(int ac, char **av, int *c);
void		free_all(int **stacks, char *line);
void		sale_sort(int **stacks);
void		sa(int **stacks, int u);
void		sb(int **stacks, int u);
void		ss(int **stacks, int u);
void		pa(int **stacks, int u);
void		pb(int **stacks, int u);
void		ra(int **stacks, int u);
void		rb(int **stacks, int u);
void		rr(int **stacks, int u);
void		rra(int **stacks, int u);
void		rrb(int **stacks, int u);
void		rrr(int **stacks, int u);

#endif
