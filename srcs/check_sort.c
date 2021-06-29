/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 17:12:49 by aldubar           #+#    #+#             */
/*   Updated: 2021/03/30 12:58:39 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	sorted_a(t_stack *a)
{
	int		nb;
	int		nb_next;

	while (a)
	{
		if (stack_size(a) == 1)
			return (1);
		if (a && a->next)
		{
			nb = a->nb;
			nb_next = a->next->nb;
		}
		if (nb < nb_next)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int			check_sort(t_stack **a, t_stack **b)
{
	if (sorted_a(*a) && !stack_size(*b))
		return (1);
	else
		return (0);
}
