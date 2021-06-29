/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:23:02 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/07 12:14:42 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	shift_up(t_stack *stack)
{
	int		first;
	int		tmp;

	first = stack->nb;
	while (stack->next)
	{
		tmp = stack->nb;
		stack->nb = stack->next->nb;
		stack->next->nb = tmp;
		stack = stack->next;
	}
	stack->nb = first;
}

void		rotate(t_stack **stack, char c, enum e_bol display)
{
	if (c == 'a' && display == TRUE)
		ft_putstr("ra\n");
	else if (c == 'b' && display == TRUE)
		ft_putstr("rb\n");
	if (stack_size(*stack) < 2)
		return ;
	shift_up(*stack);
}

void		rotate_both(t_stack **a, t_stack **b, enum e_bol display)
{
	if (display == TRUE)
		ft_putstr("rr\n");
	rotate(a, 'a', FALSE);
	rotate(b, 'b', FALSE);
}
