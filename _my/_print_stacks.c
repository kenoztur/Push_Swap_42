/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   _print_stacks.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 22:01:49 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/10 22:01:52 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_print_stacks(t_stacks stacks)
{
	int	i;

	printf("\n---- Stack a -----\n");
	printf("Size = %d\n", stacks.a->size);
	i = 0;
	while (i < stacks.a->size)
	{
		printf("%d. Paramater = %d\n", i + 1, stacks.a->numbers[i]);
		i++;
	}
	printf("\n---- Stack b -----\n");
	printf("Size = %d\n", stacks.b->size);
	i = 0;
	while (i < stacks.b->size)
	{
		printf("%d. Paramater = %d\n", i + 1, stacks.b->numbers[i]);
		i++;
	}
	printf("\n");
}
