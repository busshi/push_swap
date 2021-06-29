/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:51:11 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/12 00:26:40 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void		lastest_rotates(t_stack **a, t_option *option)
{
	size_t	op;
	size_t	pos;

	if (option->reverse)
		pos = find_pos(*a, MAX);
	else
		pos = find_pos(*a, MIN);
	op = pos;
	if (pos >= stack_size(*a) / 2)
		op = stack_size(*a) - pos;
	while (op--)
	{
		if (pos < stack_size(*a) / 2)
			rotate(a, 'a', TRUE);
		else
			reverse_rotate(a, 'a', TRUE);
	}
}

static size_t	pop_pos(int nb, t_stack **stack, t_option *option)
{
	t_stack	*tmp;
	size_t	pos;
	int		prev_nb;

	pos = 0;
	tmp = *stack;
	if (nb > find_max(*stack) && option->reverse)
		return (find_pos(*stack, MIN) + 1);
	else if (nb < find_min(*stack) && option->reverse)
		return (find_pos(*stack, MAX));
	else if (nb > find_max(*stack) && !option->reverse)
		return (find_pos(*stack, MAX) + 1);
	else if (nb < find_min(*stack) && !option->reverse)
		return (find_pos(*stack, MIN));
	prev_nb = (*stack)->nb;
	while (tmp)
	{
		if ((prev_nb < nb && nb < tmp->nb && !option->reverse) ||
				(prev_nb > nb && nb > tmp->nb && option->reverse))
			return (pos);
		prev_nb = tmp->nb;
		tmp = tmp->next;
		pos++;
	}
	return (0);
}

static void		pop(t_stack **a, t_stack **b, t_option *option)
{
	size_t	pos;
	size_t	op;
	size_t	size;

	while (stack_size(*b) > 0)
	{
		pos = pop_pos((*b)->nb, a, option);
		op = pos;
		size = stack_size(*a);
		if (pos >= size / 2)
			op = size - pos;
		while (op--)
		{
			if (pos < stack_size(*a) / 2)
				rotate(a, 'a', TRUE);
			else
				reverse_rotate(a, 'a', TRUE);
		}
		push(b, a, 'a', TRUE);
	}
	lastest_rotates(a, option);
}

void			push_and_pop(t_stack **a, t_stack **b, t_option *option)
{
	size_t	pos;
	size_t	size;

	pos = 0;
	size = stack_size(*a);
	while (size > 2)
	{
		if (option->reverse)
			pos = find_pos(*a, MAX);
		else
			pos = find_pos(*a, MIN);
		size = stack_size(*a);
		if (pos == 0)
			push(a, b, 'b', TRUE);
		else if (pos < size / 2)
			rotate(a, 'a', TRUE);
		else
			reverse_rotate(a, 'a', TRUE);
	}
	pop(a, b, option);
}

void			exec_op(t_op *op, t_stack **a, t_stack **b)
{
	while (op->a_b--)
	{
		if (op->reverse_a && op->reverse_b)
			reverse_rotate_both(a, b, TRUE);
		else
			rotate_both(a, b, TRUE);
	}
	while (op->a--)
	{
		if (op->reverse_a)
			reverse_rotate(a, 'a', TRUE);
		else
			rotate(a, 'a', TRUE);
	}
	while (op->b--)
	{
		if (op->reverse_b)
			reverse_rotate(b, 'b', TRUE);
		else
			rotate(b, 'b', TRUE);
	}
	push(a, b, 'b', TRUE);
}
