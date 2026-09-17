/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algorithm_selection_sort.c                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/14 17:46:13 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/16 15:31:27 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_index(t_stack *a)
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

static void	order(t_stacks stacks, int min_i, t_counter *counter)
{
	if (min_i > stacks.a->size / 2)
	{
		while (min_i++ < stacks.a->size)
			operation(O_RRA, stacks, counter);
	}
	else
	{
		while (min_i-- > 0)
			operation(O_RA, stacks, counter);
	}
}

static int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->numbers[i] > stack->numbers[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_three(t_stacks stacks, t_counter *counter)
{
	int	*n;

	if (stacks.a->size == 2 && stacks.a->numbers[0] > stacks.a->numbers[1])
		operation(O_SA, stacks, counter);
	if (stacks.a->size != 3)
		return ;
	n = stacks.a->numbers;
	if (n[0] < n[1] && n[1] < n[2])
		return ;
	else if (n[0] < n[1] && n[0] < n[2] && n[1] > n[2])
	{
		operation(O_SA, stacks, counter);
		operation(O_RA, stacks, counter);
	}
	else if (n[0] > n[1] && n[0] < n[2])
		operation(O_SA, stacks, counter);
	else if (n[0] < n[1] && n[0] > n[2])
		operation(O_RRA, stacks, counter);
	else if (n[0] > n[1] && n[0] > n[2] && n[1] < n[2])
		operation(O_RA, stacks, counter);
	else if (n[0] > n[1] && n[1] > n[2])
	{
		operation(O_SA, stacks, counter);
		operation(O_RRA, stacks, counter);
	}
}

void	selection_sort(t_stacks stacks, t_counter *counter)
{
	while (stacks.a->size > 3)
	{
		order(stacks, min_index(stacks.a), counter);
		if (is_sorted(stacks.a))
			break ;
		operation(O_PB, stacks, counter);
	}
	if (stacks.a->size <= 3)
		sort_three(stacks, counter);
	while (stacks.b->size > 0)
		operation(O_PA, stacks, counter);
}
