/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parser_get_numbers.c                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 22:04:59 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/13 19:45:31 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_number(char *str, int *is_error)
{
	size_t	i;
	long	number;
	int		sign;

	sign = 1;
	number = 0;
	i = 0;
	if (!(str[0] == '+' || str[0] == '-' || str[0] != 0 || ft_isdigit(str[0])))
		return (*is_error = 1, -1);
	if (str[0] == '+' || str[0] == '-')
	{
		if (str[0] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		number = number * 10 + str[i] - '0';
		if (number * sign > INT_MAX || number * sign < INT_MIN)
			return (*is_error = 1, -1);
		i++;
	}
	if ((str[i] != 0) || ((str[0] == '+' || str[0] == '-') && i == 1))
		return (*is_error = 1, -1);
	return (number * sign);
}

static int	is_dublicate(int *numbers, int *error)
{
	int	i;
	int	j;

	i = 1;
	while (i <= numbers[0])
	{
		j = 1;
		while (j < i)
		{
			if (numbers[i] == numbers[j])
				return (*error = 1, -1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	args_counter(char **args)
{
	size_t	i;

	i = 0;
	while (args[i] != NULL)
		i++;
	return (i);
}

int	*get_numbers(char **args, int *error)
{
	int	*numbers;
	int	count;
	int	number;
	int	i;

	count = args_counter(args);
	numbers = malloc((count + 1) * sizeof(int));
	if (numbers == NULL)
		return (*error = 1, NULL);
	numbers[0] = count;
	i = 1;
	while (i <= count)
	{
		number = get_number(args[i - 1], error);
		if (*error == 1)
			return (free(numbers), NULL);
		numbers[i++] = number;
	}
	is_dublicate(numbers, error);
	if (*error)
		return (free(numbers), NULL);
	return (numbers);
}
