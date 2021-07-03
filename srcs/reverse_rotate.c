/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:23:02 by aldubar           #+#    #+#             */
/*   Updated: 2021/07/03 13:00:12 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	shift_down(t_stack *stack, size_t size)
{
	int		*tab;
	size_t	i;
	t_stack	*save;

	i = 0;
	save = stack;
	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
		return ;
	while (stack->next)
	{
		tab[i] = stack->nb;
		i++;
		stack = stack->next;
	}
	i = 0;
	stack = save;
	while (stack->next)
	{
		stack->next->nb = tab[i];
		i++;
		stack = stack->next;
	}
	free(tab);
}

void		reverse_rotate(t_stack **stack, char c, enum e_bol display)
{
	int		last;
	int		size;

	if (c == 'a' && display == TRUE)
		ft_putstr("rra\n");
	else if (c == 'b' && display == TRUE)
		ft_putstr("rrb\n");
	size = stack_size(*stack);
	if (size < 2)
		return ;
	last = find_last(*stack);
	shift_down(*stack, size - 1);
	(*stack)->nb = last;
}

void		reverse_rotate_both(t_stack **a, t_stack **b, enum e_bol display)
{
	if (display == TRUE)
		ft_putstr("rrr\n");
	reverse_rotate(a, 'a', FALSE);
	reverse_rotate(b, 'b', FALSE);
}
