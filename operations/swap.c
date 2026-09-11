/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   swap.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 21:58:57 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/10 21:59:02 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack)
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
	return ;
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
	return ;
}

void	ss(t_stacks stacks)
{
	swap(stacks.a);
	swap(stacks.b);
	ft_putendl_fd("ss", 1);
	return ;
}
