/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 22:07:10 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/14 16:52:03 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			error;
	t_parse		parsed;
	t_counter	count;
	double		disorder;

	if (argc < 2)
		return (0);
	error = 0;
	parsed = parse(argc, argv, &error);
	if (error == 1)
		return (ft_putendl_fd("Error", 2), 0);
	count = init_counter();
	disorder = calculate_disorder(parsed.stakcs.a);
	algo(parsed.flags.algo, parsed.stakcs, &count, disorder);
	if (parsed.flags.is_bench)
		bench_mode(parsed, count, disorder);
	free_all(parsed.stakcs);
	return (0);
}
