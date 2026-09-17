/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operation_rotate.c                                :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kenoztur <kenoztur@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/14 17:46:52 by kenoztur         #+#    #+#              */
/*   Updated: 2026/09/14 17:46:52 by kenoztur        ###   ########.fr        */
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

void	ra(t_stack *a)
{
	rotate(a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stacks stacks)
{
	rotate(stacks.a);
	rotate(stacks.b);
	ft_putendl_fd("rr", 1);
}
