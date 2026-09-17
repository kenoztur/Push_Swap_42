/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algorithm_medium.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/13 11:37:42 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/16 15:30:25 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium(t_stacks stacks, t_counter *counter)
{
	int	i;
	int	count;

	if (stacks.a->size <= 3)
		return (sort_three(stacks, counter));
	count = digit_count(stacks.a->size);
	i = count / 2;
	count = count / 2 + i;
	while (i < count)
		step(stacks, counter, i++);
	return (selection_sort(stacks, counter));
}
