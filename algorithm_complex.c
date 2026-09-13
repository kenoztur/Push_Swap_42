/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algorithm_complex.c                               :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 23:03:33 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/13 19:43:16 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	digit_count(int number)
{
	int	i;

	i = 1;
	while (number > 1)
	{
		number /= 2;
		i++;
	}
	return (i);
}

int	is_all_zero(t_stack *a, int index, int size, int step)
{
	int	i;

	i = 0;
	while (index + i < size)
	{
		if (((a->numbers[i] >> step) & 1) == 1)
			return (0);
		i++;
	}
	return (1);
}

void	step(t_stacks stacks, t_counter *counter, int step, int is_bench)
{
	int	i;
	int	size;

	i = 0;
	size = stacks.a->size;
	while (i < size)
	{
		if (is_all_zero(stacks.a, i, size, step))
			break ;
		if (((stacks.a->numbers[0] >> step) & 1) == 0)
			operation(O_PB, stacks, counter, is_bench);
		else
			operation(O_RA, stacks, counter, is_bench);
		i++;
	}
	while (stacks.b->size > 0)
		operation(O_PA, stacks, counter, is_bench);
}

void	complex(t_stacks stacks, t_counter *counter, int is_bench)
{
	int	i;
	int	count;

	if (stacks.a->size < 8)
		return (simple(stacks, counter, is_bench));
	i = 0;
	count = digit_count(stacks.a->size - 1);
	while (i < count)
		step(stacks, counter, i++, is_bench);
	return ;
}
