/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   reverse.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 21:59:21 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/10 21:59:44 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse(t_stack *stack)
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
	reverse(a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack *b)
{
	reverse(b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stacks stacks)
{
	reverse(stacks.a);
	reverse(stacks.b);
	ft_putendl_fd("rr", 1);
}
