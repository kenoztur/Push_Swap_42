/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   get_numbers.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 22:04:59 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/10 22:23:43 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_inrange(long number)
{
	if (number < INT_MIN || number > INT_MAX)
		return (0);
	return (1);
}

int	get_number(char *str, int *is_error)
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
		if (!is_inrange(number * sign))
			return (*is_error = 1, -1);
		i++;
	}
	if ((str[i] != 0) || ((str[0] == '+' || str[0] == '-') && i == 1))
		return (*is_error = 1, -1);
	return (number * sign);
}

int	is_dublicate(int *numbers, int *error)
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

int	args_counter(char **args)
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
			return (*error = 1, NULL);
		numbers[i++] = number;
	}
	is_dublicate(numbers, error);
	return (numbers);
}
