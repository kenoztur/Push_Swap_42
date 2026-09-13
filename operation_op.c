/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   operation_op.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 22:00:25 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/13 19:48:08 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation(t_op op, t_stacks stacks, t_counter *counter, int is_bench)
{
	if (op == O_SA)
		return ((*counter).sa++, sa(stacks.a, is_bench), 1);
	else if (op == O_SB)
		return ((*counter).sb++, sb(stacks.b, is_bench), 1);
	else if (op == O_SS)
		return ((*counter).ss++, ss(stacks, is_bench), 1);
	else if (op == O_PA)
		return ((*counter).pa++, pa(stacks, is_bench), 1);
	else if (op == O_PB)
		return ((*counter).pb++, pb(stacks, is_bench), 1);
	else if (op == O_RA)
		return ((*counter).ra++, ra(stacks.a, is_bench), 1);
	else if (op == O_RB)
		return ((*counter).rb++, rb(stacks.b, is_bench), 1);
	else if (op == O_RR)
		return ((*counter).rr++, rr(stacks, is_bench), 1);
	else if (op == O_RRA)
		return ((*counter).rra++, rra(stacks.a, is_bench), 1);
	else if (op == O_RRB)
		return ((*counter).rrb++, rrb(stacks.b, is_bench), 1);
	else if (op == O_RRR)
		return ((*counter).rrr++, rrr(stacks, is_bench), 1);
	return (0);
}
