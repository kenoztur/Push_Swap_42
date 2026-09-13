/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algorithm_medium.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/13 11:37:42 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/13 19:43:13 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium(t_stacks stacks, t_counter *counter, int is_bench)
{
	int	i;
	int	count;

	if (stacks.a->size < 8)
		return (simple(stacks, counter, is_bench));
	count = digit_count(stacks.a->size);
	i = count / 2;
	count = count / 2 + i;
	while (i < count)
		step(stacks, counter, i++, is_bench);
	return (simple(stacks, counter, is_bench));
}
