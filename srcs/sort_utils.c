/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 23:03:38 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/08 00:25:27 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		find_last(t_stack *stack)
{
	int		last;

	while (stack->next)
		stack = stack->next;
	last = stack->nb;
	return (last);
}

int		find_min(t_stack *stack)
{
	int		min;

	min = stack->nb;
	while (stack)
	{
		if (stack->nb < min)
			min = stack->nb;
		stack = stack->next;
	}
	return (min);
}

int		find_max(t_stack *stack)
{
	int		max;

	max = stack->nb;
	while (stack)
	{
		if (stack->nb > max)
			max = stack->nb;
		stack = stack->next;
	}
	return (max);
}

size_t	find_pos(t_stack *stack, enum e_value value)
{
	size_t	pos;
	int		nb;

	pos = 0;
	if (value == MAX)
		nb = find_max(stack);
	else if (value == MIN)
		nb = find_min(stack);
	while (stack)
	{
		if (stack->nb == nb)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}
