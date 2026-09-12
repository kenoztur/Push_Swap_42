/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenoztur <kenoztur@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 23:00:17 by esadikog          #+#    #+#             */
/*   Updated: 2026/09/12 23:26:53 by kenoztur         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../push_swap.h"

int	my_sqrt(int n)
{
	int i;

	if(n <= 0)
		return (0);
	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

int	*get_indexes(t_stack *a)
{
	int *indexes;
	int i;
	int j;
	int count;

	indexes = malloc(sizeof(int) * a->size);
	if (!indexes)
		return (NULL);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		count = 0;
		while (j < a->size)
		{
			if (a->numbers[j] < a->numbers[i])
				count++;
			j++;
		}
		indexes[i] = count;
		i++;
	}
	return (indexes);
}
int max_index(t_stack *b)
{
	int max;
	int max_i;
	int i;
	
	if(b->size == 0)
		return (0);
	max = b->numbers[0];
	max_i = 0;
	i = 1;
	while (i < b->size)
	{
		if (b->numbers[i] > max)
		{
			max = b->numbers[i];
			max_i = i;
		}
		i++;
	}
	return (max_i);
}

void	order_b(t_stacks stacks, int max_i, t_counter *counter)
{
	if (max_i > stacks.b->size / 2)
	{
		while (max_i < stacks.b->size)
		{
			operation(O_RRB, stacks, counter);
			max_i++;
		}
	}
	else
	{
		while (max_i > 0)
		{
			operation(O_RB, stacks, counter);
			max_i--;
		}
	}
}

void	medium(t_stacks stacks, t_counter *counter)
{
	int *index;
	int *i;
	int chunk;

	i = 0;
	chunk = my_sqrt(stacks.a->size);
	while (stacks.a->size > 0)
	{
		index = get_indexes(stacks.a);
		if (!index)
			return ;
		if (index[0] <= i)
		{
			operation(O_PB, stacks, counter);
			operation(O_RB, stacks, counter);
			i++;
		}
		else if(index[0] <= i + chunk)
		{
			operation(O_PB, stacks, counter);
			i++;
		}
		else
			operation(O_RA, stacks, counter);
		free(index);
	}
	while (stacks.b->size > 0)
	{
		order_b(stacks, max_index(stacks.b), counter);
		operation(O_PA, stacks, counter);
	}
}
