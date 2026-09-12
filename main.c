/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 22:07:10 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/11 06:21:33 by esadikog        ###   ########.fr        */
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
//here

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
	// while (i < size && !is_all_zero(stacks.a, i, size, step))
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

void	complexx(t_stacks stacks, t_counter *counter)
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

void	select_algo(char *algo, t_stacks stacks, t_counter *counter, double di)
{
	if (stacks.a->size <= 1)
		return ;
	if (algo == NULL || ft_strncmp(algo, "--adaptive", 11) == 0)
	{
		if (di < 0.2)
			simple(stacks, counter);
		else if (di >= 0.2 && di < 0.5)
			medium(stacks, counter);
		else
			complexx(stacks, counter);
	}
	else if (ft_strncmp(algo, "--simple", 9) == 0)
		simple(stacks, counter);
	else if (ft_strncmp(algo, "--medium", 9) == 0)
		medium(stacks, counter);
	else if (ft_strncmp(algo, "--complex", 10) == 0)
		complexx(stacks, counter);
}

int	main(int argc, char **argv)
{
	int			error;
	t_parse		parsed;
	t_counter	counter;
	double		disorder;

	if (argc < 2)
		return (0);
	error = 0;
	parsed = parse(argc, argv, &error);
	if (error == 1)
		return (ft_putendl_fd("Error", 1), 0);
	counter = init_counter();
	disorder = calculate_disorder(parsed.stakcs.a);
	select_algo(parsed.flags.algo, parsed.stakcs, &counter, disorder);
	return (0);
}
