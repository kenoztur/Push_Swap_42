/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   r_reverse.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 22:00:12 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/10 22:00:14 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r_reverse(t_stack *stack)
{
	int	repo;
	int	*s;

	repo = stack->numbers[stack->size - 1];
	s = stack->numbers;
	ft_memmove(s + 1, s, (stack->size - 1) * sizeof(int));
	stack->numbers[0] = repo;
}

void	rra(t_stack *a)
{
	r_reverse(a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *b)
{
	r_reverse(b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stacks stacks)
{
	r_reverse(stacks.a);
	r_reverse(stacks.b);
	ft_putendl_fd("rrr", 1);
}
