/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   simple.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 23:00:38 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/11 02:22:41 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	min_index(t_stack *a)
{
	int	min;
	int	i;
	int	min_i;

	i = 0;
	min = a->numbers[0];
	min_i = 0;
	while (i < a->size)
	{
		if (a->numbers[i] < min)
		{
			min = a->numbers[i];
			min_i = i;
		}
		i++;
	}
	return (min_i);
}

void	order(t_stacks stacks, int min_i, t_counter *counter)
{
	if (min_i > stacks.a->size / 2)
	{
		while (min_i < stacks.a->size)
		{
			operation(O_RRA, stacks, counter);
			min_i++;
		}
	}
	else
	{
		while (min_i > 0)
		{
			operation(O_RA, stacks, counter);
			min_i--;
		}
	}
}

void	get_back(t_stacks stacks, t_counter *counter)
{
	while (stacks.b->size > 0)
		operation(O_PA, stacks, counter);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->size - 1)
	{
		if (a->numbers[i] > a->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	simple(t_stacks stacks, t_counter *counter)
{
	int	min_i;

	while (stacks.a->size > 2)
	{
		order(stacks, min_index(stacks.a), counter);
		if (is_sorted(stacks.a))
			break ;
		operation(O_PB, stacks, counter);
	}
	if (stacks.a->numbers[0] > stacks.a->numbers[1])
		operation(O_SA, stacks, counter);
	get_back(stacks, counter);
}
