/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operation_op.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/17 17:19:29 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/17 17:20:52 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation(t_op op, t_stacks stacks, t_counter *counter)
{
	if (op == O_SA)
		return ((*counter).sa++, sa(stacks.a), 1);
	else if (op == O_SB)
		return ((*counter).sb++, sb(stacks.b), 1);
	else if (op == O_SS)
		return ((*counter).ss++, ss(stacks), 1);
	else if (op == O_PA)
		return ((*counter).pa++, pa(stacks), 1);
	else if (op == O_PB)
		return ((*counter).pb++, pb(stacks), 1);
	else if (op == O_RA)
		return ((*counter).ra++, ra(stacks.a), 1);
	else if (op == O_RB)
		return ((*counter).rb++, rb(stacks.b), 1);
	else if (op == O_RR)
		return ((*counter).rr++, rr(stacks), 1);
	else if (op == O_RRA)
		return ((*counter).rra++, rra(stacks.a), 1);
	else if (op == O_RRB)
		return ((*counter).rrb++, rrb(stacks.b), 1);
	else if (op == O_RRR)
		return ((*counter).rrr++, rrr(stacks), 1);
	return (0);
}
