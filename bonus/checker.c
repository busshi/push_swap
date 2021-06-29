/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:25:55 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/11 16:46:06 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void		run_checker(char **tab, t_stack **a, t_stack **b,
		t_option *option)
{
	if (check_input(tab) && create_stack(tab, a))
	{
		ft_free_tab(tab);
		read_cmd(a, b, option);
	}
	else
	{
		ft_free_tab(tab);
		if (option->color)
			ft_putstr_fd("\033[0;31mError\n\033[0;m", 2);
		else
			ft_putstr_fd("Error\n", 2);
	}
}

int				main(int ac, char **av)
{
	char		**tab;
	t_stack		*a;
	t_stack		*b;
	t_option	*option;
	int			i;

	a = NULL;
	b = NULL;
	tab = NULL;
	i = 0;
	option = init_option();
	if (!option)
		return (-1);
	if (ac >= 2)
	{
		i += check_option(option, av);
		tab = create_tab(av + i);
	}
	if (tab)
		run_checker(tab, &a, &b, option);
	free(option);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
