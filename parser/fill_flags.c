/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   fill_flags.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: esadikog <esadikog@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/10 22:02:44 by esadikog         #+#    #+#              */
/*   Updated: 2026/09/10 22:03:44 by esadikog        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*is_flag(char *str)
{
	if (ft_strncmp(str, "--simple", 9) == 0)
		return ("--simple");
	if (ft_strncmp(str, "--medium", 9) == 0)
		return ("--medium");
	if (ft_strncmp(str, "--complex", 10) == 0)
		return ("--complex");
	if (ft_strncmp(str, "--adaptive", 11) == 0)
		return ("--adaptive");
	if (ft_strncmp(str, "--bench", 8) == 0)
		return ("--bench");
	return (0);
}

t_flags	init_flags(void)
{
	t_flags	flags;

	flags.algo = NULL;
	flags.is_bench = 0;
	return (flags);
}

int	fill_flags(t_flags *flags, char **args, int *error)
{
	int		i;
	char	*response;

	i = 0;
	while (args[i])
	{
		if ((response = is_flag(args[i++])))
		{
			if (ft_strncmp(response, "--bench", 8) == 0)
			{
				if (flags->is_bench == 1)
					return (*error = 1, 0);
				flags->is_bench = 1;
			}
			else
			{
				if (flags->algo != NULL)
					return (*error = 1, 0);
				flags->algo = response;
			}
			continue ;
		}
		break ;
	}
	return (1);
}
