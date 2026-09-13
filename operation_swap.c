/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operation_swap.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 21:58:57 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/13 19:45:21 by esadikog        ###   ########.fr        */
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

void	sa(t_stack *a, int is_bench)
{
	swap(a);
	if (!is_bench)
		ft_putendl_fd("sa", 1);
}

void	sb(t_stack *b, int is_bench)
{
	swap(b);
	if (!is_bench)
		ft_putendl_fd("sb", 1);
}

void	ss(t_stacks stacks, int is_bench)
{
	swap(stacks.a);
	swap(stacks.b);
	if (!is_bench)
		ft_putendl_fd("ss", 1);
}
