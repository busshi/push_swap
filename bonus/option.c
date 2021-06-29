/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 20:45:13 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/12 20:30:20 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static int	check_option_next(t_option *option, char **av)
{
	if (av[3] && ((option->color && option->verbose) ||
				(option->color && option->reverse) ||
				(option->verbose && option->reverse)))
	{
		if (!option->color && !ft_strcmp(av[3], "-c"))
			option->color = 1;
		else if (!option->verbose && !ft_strcmp(av[3], "-v"))
			option->verbose = 1;
		else if (!option->reverse && !ft_strcmp(av[3], "-r"))
			option->reverse = 1;
	}
	return (option->color + option->verbose + option->reverse);
}

int			check_option(t_option *option, char **av)
{
	int		i;

	i = 0;
	if (av[1])
	{
		if (!ft_strcmp(av[1], "-c"))
			option->color = 1;
		else if (!ft_strcmp(av[1], "-v"))
			option->verbose = 1;
		else if (!ft_strcmp(av[1], "-r"))
			option->reverse = 1;
	}
	if (av[2] && (option->color || option->verbose || option->reverse))
	{
		if (!option->color && !ft_strcmp(av[2], "-c"))
			option->color = 1;
		else if (!option->verbose && !ft_strcmp(av[2], "-v"))
			option->verbose = 1;
		else if (!option->reverse && !ft_strcmp(av[2], "-r"))
			option->reverse = 1;
	}
	return (check_option_next(option, av));
}

t_option	*init_option(void)
{
	t_option	*option;

	option = (t_option *)malloc(sizeof(t_option));
	if (!option)
		return (NULL);
	option->color = 0;
	option->verbose = 0;
	option->reverse = 0;
	option->exit = 0;
	option->next = 0;
	option->min_a = 0;
	option->min_b = 0;
	option->max_a = 0;
	option->max_b = 0;
	option->min = 0;
	option->max = 0;
	option->current = 0;
	return (option);
}
