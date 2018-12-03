/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 22:24:26 by tduval            #+#    #+#             */
/*   Updated: 2018/12/03 01:46:05 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_h

int			**cat_params(int ac, char **av, int *c);
void		free_all(int **stacks);
void		sale_sort(int **stacks);
void		sa(int **stacks);
void		sb(int **stacks);
void		ss(int **stacks);
void		pa(int **stacks);
void		pb(int **stacks);
void		ra(int **stacks);
void		rb(int **stacks);
void		rr(int **stacks);
void		rra(int **stacks);
void		rrb(int **stacks);
void		rrr(int **stacks);

#endif
