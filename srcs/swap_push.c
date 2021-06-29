/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:21:51 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/06 13:12:40 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack, char c, enum e_bol display)
{
	int	nb1;
	int	nb2;

	if (c == 'a' && display == TRUE)
		ft_putstr("sa\n");
	else if (c == 'b' && display == TRUE)
		ft_putstr("sb\n");
	if (stack_size(*stack) < 2)
		return ;
	nb1 = (*stack)->nb;
	nb2 = (*stack)->next->nb;
	(*stack)->nb = nb2;
	(*stack)->next->nb = nb1;
}

void	swap_both(t_stack **a, t_stack **b, enum e_bol display)
{
	if (display == TRUE)
		ft_putstr("ss\n");
	swap(a, 'a', FALSE);
	swap(b, 'b', FALSE);
}

void	push(t_stack **src, t_stack **dest, char c, enum e_bol display)
{
	t_stack	*new;

	if (c == 'a' && display == TRUE)
		ft_putstr("pa\n");
	else if (c == 'b' && display == TRUE)
		ft_putstr("pb\n");
	if (!stack_size(*src))
		return ;
	new = new_elem((*src)->nb);
	add_stack_front(dest, new);
	delone_stack(src);
}
