/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:25:55 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/08 22:27:58 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			main(int ac, char **av)
{
	char	**tab;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	tab = NULL;
	if (ac >= 2)
		tab = create_tab(av);
	if (tab)
	{
		if (check_input(tab) && create_stack(tab, &a))
		{
			ft_free_tab(tab);
			read_cmd(&a, &b);
		}
		else
		{
			ft_free_tab(tab);
			ft_putstr_fd("Error\n", 2);
		}
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
