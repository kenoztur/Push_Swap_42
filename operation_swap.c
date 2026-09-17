/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operation_swap.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: kenoztur <kenoztur@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/14 17:46:56 by kenoztur         #+#    #+#              */
/*   Updated: 2026/09/14 17:46:56 by kenoztur        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *stack)
{
	int	repo;

	if (stack->size < 2)
		return ;
	repo = stack->numbers[0];
	stack->numbers[0] = stack->numbers[1];
	stack->numbers[1] = repo;
}

void	sa(t_stack *a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stacks stacks)
{
	swap(stacks.a);
	swap(stacks.b);
	ft_putendl_fd("ss", 1);
}
