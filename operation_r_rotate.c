/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operation_r_rotate.c                              :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 22:00:12 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/13 19:45:15 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	r_rotate(t_stack *stack)
{
	int	repo;
	int	*s;

	repo = stack->numbers[stack->size - 1];
	s = stack->numbers;
	ft_memmove(s + 1, s, (stack->size - 1) * sizeof(int));
	stack->numbers[0] = repo;
}

void	rra(t_stack *a, int is_bench)
{
	r_rotate(a);
	if (!is_bench)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *b, int is_bench)
{
	r_rotate(b);
	if (!is_bench)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_stacks stacks, int is_bench)
{
	r_rotate(stacks.a);
	r_rotate(stacks.b);
	if (!is_bench)
		ft_putendl_fd("rrr", 1);
}
