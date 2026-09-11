/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parse.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 22:03:55 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/10 22:31:27 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../push_swap.h"

char	**get_args(int argc, char **argv)
{
	char	*str;
	int		i;
	char	**args;

	i = 1;
	str = ft_strdup(" ");
	while (i < argc)
	{
		str = ft_strjoin(str, argv[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	args = ft_split(str, ' ');
	return (args);
}

t_stacks	init_stacks(int *numbers, int *error)
{
	t_stack		*a;
	t_stack		*b;
	t_stacks	stacks;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	if (a == NULL || b == NULL)
		return (*error = 1, stacks);
	a->numbers = malloc(numbers[0] * sizeof(int));
	b->numbers = ft_calloc(numbers[0], sizeof(int));
	if (a->numbers == NULL || b->numbers == NULL)
		return (*error = 1, stacks);
	ft_memmove(a->numbers, numbers + 1, numbers[0] * sizeof(int));
	a->size = numbers[0];
	b->size = 0;
	stacks.a = a;
	stacks.b = b;
	return (stacks);
}

t_parse	parse(int argc, char **argv, int *error)
{
	char	**args;
	t_flags	flags;
	int		*numbers;
	t_parse	parse;

	args = get_args(argc, argv);
	flags = init_flags();
	fill_flags(&flags, args, error);
	parse.flags = flags;
	if (*error == 1)
		return (parse);
	numbers = get_numbers(args + flags.is_bench + (flags.algo != NULL), error);
	if (*error == 1)
		return (parse);
	parse.stakcs = init_stacks(numbers, error);
	free(numbers);
	if (*error == 1)
		return (parse);
	return (parse);
}
