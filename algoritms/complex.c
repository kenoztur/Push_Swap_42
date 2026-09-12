/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   complex.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 23:03:33 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/11 06:28:52 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	digit_count(t_stack *a)
{
	int	max;
	int	i;

	i = 0;
	max = INT_MIN;
	while (i < a->size)
	{
		if (a->numbers[i] > max)
			max = a->numbers[i];
		i++;
	}
	i = 1;
	while (max > 1)
	{
		max /= 2;
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

void	step(t_stacks stacks, t_counter *counter, int step)
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
			operation(O_PB, stacks, counter);
		else
			operation(O_RA, stacks, counter);
		i++;
	}
	while (stacks.b->size > 0)
		operation(O_PA, stacks, counter);
}

void	complex(t_stacks stacks, t_counter *counter)
{
	int	i;
	int	count;

	i = 0;
	count = digit_count(stacks.a);
	while (i < count)
	{
		step(stacks, counter, i);
		i++;
	}
	_print_stacks(stacks);
	return ;
}
