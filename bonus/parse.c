/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:22:50 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/08 15:49:15 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static int	check_double(t_stack *stack)
{
	int		i;
	int		nb;
	int		j;
	int		size;
	t_stack	*tmp;

	i = -1;
	j = 1;
	size = stack_size(stack);
	tmp = stack;
	while (++i < size)
	{
		nb = tmp->nb;
		while (tmp->next)
		{
			if (nb == tmp->next->nb)
				return (0);
			tmp = tmp->next;
		}
		tmp = stack;
		while (j-- > 0)
			tmp = tmp->next;
		j = size - stack_size(tmp) + 1;
	}
	return (1);
}

static int	push_stack(t_stack **stack, char **tab)
{
	int			i;
	long long	nb;
	t_stack		*new;

	i = ft_tab_len(tab) - 1;
	while (i >= 0)
	{
		nb = ft_atoi_long(tab[i]);
		if (nb < -2147483648 || nb > 2147483647)
			return (0);
		new = new_elem((int)nb);
		add_stack_front(stack, new);
		i--;
	}
	return (1);
}

int			create_stack(char **tab, t_stack **a)
{
	if (!push_stack(a, tab))
		return (0);
	if (!check_double(*a))
		return (0);
	return (1);
}

int			check_input(char **tab)
{
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (ft_isspace(tab[i][j]))
			j++;
		if (tab[i][j] == '-' || tab[i][j] == '+')
			j++;
		while (ft_isdigit(tab[i][j]))
			j++;
		while (ft_isspace(tab[i][j]))
			j++;
		if (tab[i][j])
			return (0);
		i++;
	}
	return (1);
}

char		**create_tab(char **av)
{
	char	**tab;
	char	**tmp;
	int		i;

	i = 1;
	tab = NULL;
	while (av[i])
	{
		tmp = ft_split(av[i], ' ');
		if (!tmp)
			return (NULL);
		tab = ft_tab_join(tab, tmp);
		if (tmp)
			ft_free_tab(tmp);
		if (!tab)
			return (NULL);
		i++;
	}
	return (tab);
}
