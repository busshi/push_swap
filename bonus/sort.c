/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:37:28 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/12 23:32:09 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	sort(t_stack **a, t_stack **b, t_option *option)
{
	size_t	chunk;
	size_t	size;
	t_op	*less;

	chunk = 2;
	size = stack_size(*a);
	if (size > 500)
		chunk = 100;
	else if (size > 100)
		chunk = 50;
	push(a, b, 'b', TRUE);
	push(a, b, 'b', TRUE);
	while (size > chunk)
	{
		size = stack_size(*a);
		less = calculate_less_op(a, b, option);
		exec_op(less, a, b);
		free(less);
		less = NULL;
	}
	push_and_pop(a, b, option);
}

static void	sort_three(t_stack **stack, char pile, t_option *option)
{
	int		nb;

	if (!option->reverse)
	{
		nb = find_max(*stack);
		if ((*stack)->nb == nb)
			rotate(stack, pile, TRUE);
		else if ((*stack)->next->nb == nb)
			reverse_rotate(stack, pile, TRUE);
		if ((*stack)->nb > (*stack)->next->nb)
			swap(stack, pile, TRUE);
	}
	else
	{
		nb = find_min(*stack);
		if ((*stack)->nb == nb)
			rotate(stack, pile, TRUE);
		if ((*stack)->next->nb == nb)
			reverse_rotate(stack, pile, TRUE);
		if ((*stack)->nb < (*stack)->next->nb)
			swap(stack, pile, TRUE);
	}
}

static void	sort_five(t_stack **a, t_stack **b, size_t size, t_option *option)
{
	size_t	pos;
	size_t	op;

	op = 0;
	while (op < size - 3)
	{
		if (option->reverse)
			pos = find_pos(*a, MAX);
		else
			pos = find_pos(*a, MIN);
		size = stack_size(*a);
		if (pos <= size / 2)
			while (pos--)
				rotate(a, 'a', TRUE);
		else
			while (pos++ < size)
				reverse_rotate(a, 'a', TRUE);
		if (check_sort(a, a, option))
			return ;
		push(a, b, 'b', TRUE);
		op++;
	}
	sort_three(a, 'a', option);
	while (op--)
		push(b, a, 'a', TRUE);
}

void		sort_stack(t_stack **a, t_stack **b, t_option *option)
{
	size_t		size;

	if (check_sort(a, b, option))
		return ;
	size = stack_size(*a);
	if (size == 2)
		swap(a, 'a', TRUE);
	else if (size == 3)
		sort_three(a, 'a', option);
	else if (size == 4 || size == 5)
		sort_five(a, b, size, option);
	else
		sort(a, b, option);
}
