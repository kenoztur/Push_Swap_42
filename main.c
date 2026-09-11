/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 22:07:10 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/11 02:23:38 by esadikog        ###   ########.fr        */
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
			complex(stacks, counter);
	}
	else if (ft_strncmp(algo, "--simple", 9) == 0)
		simple(stacks, counter);
	else if (ft_strncmp(algo, "--medium", 9) == 0)
		medium(stacks, counter);
	else if (ft_strncmp(algo, "--complex", 10) == 0)
		complex(stacks, counter);
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
