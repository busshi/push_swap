/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:37:28 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/12 23:31:52 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort(t_stack **a, t_stack **b)
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
		less = calculate_less_op(a, b);
		exec_op(less, a, b);
		free(less);
		less = NULL;
	}
	push_and_pop(a, b);
}

static void	sort_three(t_stack **stack, char pile)
{
	int		max;

	max = find_max(*stack);
	if ((*stack)->nb == max)
		rotate(stack, pile, TRUE);
	else if ((*stack)->next->nb == max)
		reverse_rotate(stack, pile, TRUE);
	if ((*stack)->nb > (*stack)->next->nb)
		swap(stack, pile, TRUE);
}

static void	sort_five(t_stack **a, t_stack **b, size_t size)
{
	size_t	pos_min;
	size_t	op;

	op = 0;
	while (op < size - 3)
	{
		pos_min = find_pos(*a, MIN);
		size = stack_size(*a);
		if (pos_min <= size / 2)
			while (pos_min--)
				rotate(a, 'a', TRUE);
		else
			while (pos_min++ < size)
				reverse_rotate(a, 'a', TRUE);
		if (check_sort(a, b))
			return ;
		push(a, b, 'b', TRUE);
		op++;
	}
	sort_three(a, 'a');
	while (op--)
		push(b, a, 'a', TRUE);
}

void		sort_stack(t_stack **a, t_stack **b)
{
	size_t		size;

	if (check_sort(a, b))
		return ;
	size = stack_size(*a);
	if (size == 2)
		swap(a, 'a', TRUE);
	else if (size == 3)
		sort_three(a, 'a');
	else if (size == 4 || size == 5)
		sort_five(a, b, size);
	else
		sort(a, b);
}
