/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operation_rotate.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 21:59:21 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/13 19:45:18 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	int	*s;
	int	repo;

	repo = stack->numbers[0];
	s = stack->numbers;
	ft_memmove(s, s + 1, (stack->size - 1) * sizeof(int));
	stack->numbers[stack->size - 1] = repo;
}

void	ra(t_stack *a, int is_bench)
{
	rotate(a);
	if (!is_bench)
		ft_putendl_fd("ra", 1);
}

void	rb(t_stack *b, int is_bench)
{
	rotate(b);
	if (!is_bench)
		ft_putendl_fd("rb", 1);
}

void	rr(t_stacks stacks, int is_bench)
{
	rotate(stacks.a);
	rotate(stacks.b);
	if (!is_bench)
		ft_putendl_fd("rr", 1);
}
