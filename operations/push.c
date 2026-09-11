/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 21:56:36 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/10 21:56:50 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack *from, t_stack *to)
{
	int	*s;

	s = to->numbers;
	ft_memmove(s + 1, s, to->size * sizeof(int));
	to->numbers[0] = from->numbers[0];
	to->size += 1;
	s = from->numbers;
	ft_memmove(s, s + 1, from->size * sizeof(int));
	from->size -= 1;
	from->numbers[from->size] = 0;
}

void	pa(t_stacks stacks)
{
	if (stacks.b->size == 0)
		return ;
	push(stacks.b, stacks.a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stacks stacks)
{
	if (stacks.a->size == 0)
		return ;
	push(stacks.a, stacks.b);
	ft_putendl_fd("pb", 1);
}
