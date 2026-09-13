/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   bench_mode.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/13 14:27:37 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/13 20:23:13 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double disorder)
{
	int	first_part;
	int	second_part;

	first_part = (int)(disorder * 100);
	second_part = (disorder * 100 - (double) first_part) * 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(first_part, 2);
	ft_putchar_fd('.', 2);
	if (second_part < 10)
		ft_putnbr_fd(0, 2);
	ft_putnbr_fd(second_part, 2);
	ft_putendl_fd("%", 2);
}

static void	print_strategy(char *algo, double di)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (algo == NULL || ft_strncmp(algo, "--adaptive", 11) == 0)
	{
		if (di < 0.2)
			ft_putendl_fd("Adaptive / O(n^2)", 2);
		else if (di >= 0.2 && di < 0.5)
			ft_putendl_fd("Adaptive / O(n√n)", 2);
		else
			ft_putendl_fd("Adaptive / O(n logn)", 2);
	}
	else if (ft_strncmp(algo, "--simple", 9) == 0)
		ft_putendl_fd("Simple / O(n^2)", 2);
	else if (ft_strncmp(algo, "--medium", 9) == 0)
		ft_putendl_fd("Medium / O(n^2)", 2);
	else if (ft_strncmp(algo, "--complex", 10) == 0)
		ft_putendl_fd("Complex / O(n^2)", 2);
}

static void	print_ops(t_counter count)
{
	ft_putstr_fd("\n[bench] sa: ", 2);
	ft_putnbr_fd(count.sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(count.sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(count.ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(count.pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(count.pb, 2);
	ft_putstr_fd("\n[bench] ra: ", 2);
	ft_putnbr_fd(count.ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(count.rr, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(count.rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(count.rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(count.rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(count.rrr, 2);
	ft_putstr_fd("\n\n", 2);
}

static void	print_total_ops(t_counter count)
{
	int	op_count;

	op_count = count.sa + count.sb + count.ss + count.pa + count.pb;
	op_count += count.ra + count.rb + count.rr + count.rra + count.rrb;
	op_count += count.rrr;
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(op_count, 2);
	print_ops(count);
}

void	bench_mode(t_parse parse, t_counter counter, double disorder)
{
	print_disorder(disorder);
	print_strategy(parse.flags.algo, disorder);
	print_total_ops(counter);
}
