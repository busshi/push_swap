/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 11:44:41 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/12 00:28:03 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void		calculate_op(t_op *op)
{
	op->a_b = 0;
	if (op->reverse_a == op->reverse_b)
	{
		if (op->a < op->b)
		{
			op->a_b = op->a;
			op->b -= op->a;
			op->a = 0;
		}
		else if (op->b < op->a)
		{
			op->a_b = op->b;
			op->a -= op->b;
			op->b = 0;
		}
		else
		{
			op->a_b = op->a;
			op->a = 0;
			op->b = 0;
		}
	}
	op->op = op->a + op->b + op->a_b;
}

static size_t	push_pos(int nb, t_stack **stack, t_option *option)
{
	t_stack	*tmp;
	int		pos;
	int		prev_nb;

	pos = 0;
	tmp = *stack;
	if (nb > find_max(*stack) && option->reverse)
		return (find_pos(*stack, MIN));
	else if (nb < find_min(*stack) && option->reverse)
		return (find_pos(*stack, MAX) + 1);
	else if (nb > find_max(*stack) && !option->reverse)
		return (find_pos(*stack, MAX));
	else if (nb < find_min(*stack) && !option->reverse)
		return (find_pos(*stack, MIN) + 1);
	prev_nb = (*stack)->nb;
	while (tmp)
	{
		if ((prev_nb > nb && nb > tmp->nb && !option->reverse) ||
				(prev_nb < nb && nb < tmp->nb && option->reverse))
			return (pos);
		prev_nb = tmp->nb;
		tmp = tmp->next;
		pos++;
	}
	return (0);
}

static void		calculate_b_op(t_stack **b, t_op *op, int nb, t_option *option)
{
	size_t	size;
	size_t	pos;

	pos = push_pos(nb, b, option);
	op->b = pos;
	op->reverse_b = 0;
	size = stack_size(*b);
	if (pos >= size / 2)
	{
		op->b = size - pos;
		op->reverse_b = 1;
	}
	calculate_op(op);
}

static void		calculate_a_op(t_stack **a, t_op *op, size_t pos)
{
	size_t	size;

	size = stack_size(*a);
	op->a = pos;
	op->reverse_a = 0;
	if (pos >= size / 2)
	{
		op->a = size - pos;
		op->reverse_a = 1;
	}
}

t_op			*calculate_less_op(t_stack **a, t_stack **b, t_option *option)
{
	t_op	*op;
	t_op	*less;
	t_stack	*tmp;
	size_t	pos;

	op = NULL;
	less = NULL;
	op_init(&op, &less);
	pos = 0;
	calculate_a_op(a, less, pos);
	tmp = *a;
	calculate_b_op(b, less, tmp->nb, option);
	while (tmp)
	{
		calculate_a_op(a, op, pos);
		calculate_b_op(b, op, tmp->nb, option);
		if (op->op < less->op)
			choose_less_op(less, op);
		pos++;
		tmp = tmp->next;
	}
	free(op);
	op = NULL;
	return (less);
}
