/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 03:38:13 by tduval            #+#    #+#             */
/*   Updated: 2018/12/03 03:38:38 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_all(int **stacks, char *line)
{
	if (stacks)
	{
		if (stacks[0])
				free(stacks[0]);
		if (stacks[1])
				free(stacks[1]);
		free(stacks);
	}
	if (line)
		free(line);
}
