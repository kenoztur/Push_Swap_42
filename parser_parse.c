/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parser_parse.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 22:03:55 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/13 20:08:45 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**get_args(int argc, char **argv)
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
	free(str);
	return (args);
}

static int	*get_indexes(t_stack *a, int *error)
{
	int	i;
	int	j;
	int	count;
	int	*indexes;

	indexes = malloc(a->size * sizeof(int));
	if (!indexes)
		return (*error = 1, NULL);
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

static t_stacks	init_stacks(int *numbers, int *er)
{
	t_stacks	stacks;
	int			*indexes;

	stacks.a = NULL;
	stacks.b = NULL;
	stacks.a = malloc(sizeof(t_stack));
	stacks.b = malloc(sizeof(t_stack));
	if (stacks.a == NULL || stacks.b == NULL)
		return (free(stacks.a), free(stacks.b), *er = 1, stacks);
	stacks.a->numbers = malloc(numbers[0] * sizeof(int));
	stacks.b->numbers = ft_calloc(numbers[0], sizeof(int));
	if (stacks.a->numbers == NULL || stacks.b->numbers == NULL)
		return (free_all(stacks), *er = 1, stacks);
	ft_memmove(stacks.a->numbers, numbers + 1, numbers[0] * sizeof(int));
	stacks.a->size = numbers[0];
	stacks.b->size = 0;
	indexes = get_indexes(stacks.a, er);
	if (*er == 1)
		return (free_all(stacks), stacks);
	free(stacks.a->numbers);
	stacks.a->numbers = indexes;
	return (stacks);
}

static void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
		free(args[i++]);
	free(args);
}

t_parse	parse(int argc, char **argv, int *error)
{
	char	**args;
	t_flags	flags;
	int		*numbers;
	t_parse	parse;

	args = get_args(argc, argv);
	if (args == NULL)
		return (*error = 1, parse.flags.algo = NULL, parse);
	flags = init_flags();
	fill_flags(&flags, args, error);
	parse.flags = flags;
	if (*error == 1)
		return (free_args(args), parse);
	numbers = get_numbers(args + flags.is_bench + (flags.algo != NULL), error);
	free_args(args);
	if (*error == 1)
		return (parse);
	parse.stakcs = init_stacks(numbers, error);
	free(numbers);
	if (*error == 1)
		return (parse);
	return (parse);
}
