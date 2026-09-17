/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helper.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/13 19:49:45 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/14 14:43:52 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_counter	init_counter(void)
{
	t_counter	counter;

	counter = (t_counter)
	{
		0
	};
	return (counter);
}

double	calculate_disorder(t_stack *a)
{
	int	i;
	int	j;
	int	mistakes;
	int	total_pairs;

	if (a->size <= 1)
		return (0.0);
	i = 0;
	j = 0;
	mistakes = 0;
	total_pairs = 0;
	while (i < a->size)
	{
		j = i + 1;
		while (j < a->size)
		{
			total_pairs++;
			if (a->numbers[i] > a->numbers[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double) mistakes / (double) total_pairs);
}

void	algo(char *algo, t_stacks stacks, t_counter *count, double di)
{
	if (stacks.a->size <= 1)
		return ;
	if (algo == NULL || ft_strncmp(algo, "--adaptive", 11) == 0)
	{
		if (di < 0.2)
			simple(stacks, count);
		else if (di >= 0.2 && di < 0.5)
			medium(stacks, count);
		else
			complex(stacks, count);
	}
	else if (ft_strncmp(algo, "--simple", 9) == 0)
		simple(stacks, count);
	else if (ft_strncmp(algo, "--medium", 9) == 0)
		medium(stacks, count);
	else if (ft_strncmp(algo, "--complex", 10) == 0)
		complex(stacks, count);
}

void	free_all(t_stacks stacks)
{
	free(stacks.a->numbers);
	free(stacks.a);
	free(stacks.b->numbers);
	free(stacks.b);
}
