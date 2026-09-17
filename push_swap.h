/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/14 17:46:59 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/16 15:29:32 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_counter
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_counter;

typedef enum s_op
{
	O_SA,
	O_SB,
	O_SS,
	O_PA,
	O_PB,
	O_RA,
	O_RB,
	O_RR,
	O_RRA,
	O_RRB,
	O_RRR
}	t_op;

typedef struct s_stack
{
	int	*numbers;
	int	size;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

typedef struct s_flags
{
	char	*algo;
	int		is_bench;
}	t_flags;

typedef struct s_parse
{
	t_stacks	stakcs;
	t_flags		flags;
}	t_parse;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

void		_print_stacks(t_stacks stacks);
t_flags		init_flags(void);
int			fill_flags(t_flags *flags, char **args, int *error);
int			*get_numbers(char **args, int *error);
t_parse		parse(int argc, char **argv, int *error);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stacks stacks);
void		pa(t_stacks stacks);
void		pb(t_stacks stacks);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stacks stacks);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stacks stacks);
int			operation(t_op op, t_stacks stacks, t_counter *count);
void		selection_sort(t_stacks stacks, t_counter *counter);
void		simple(t_stacks stacks, t_counter *counter);
void		medium(t_stacks stacks, t_counter *counter);
void		complex(t_stacks stacks, t_counter *counter);
int			digit_count(int number);
void		step(t_stacks stacks, t_counter *counter, int step);
void		bench_mode(t_parse parse, t_counter counter, double disorder);
t_counter	init_counter(void);
double		calculate_disorder(t_stack *a);
void		algo(char *algo, t_stacks stacks, t_counter *count, double di);
void		free_all(t_stacks stacks);
void		sort_three(t_stacks stacks, t_counter *counter);

#endif
