/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 19:39:56 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/08 15:48:19 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	free_tab_fail(char **tab, int max)
{
	int		i;

	i = 0;
	while (i < max)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	delone_stack(t_stack **stack)
{
	t_stack	*be_free;

	be_free = *stack;
	*stack = (*stack)->next;
	free(be_free);
}

void	free_stack(t_stack **stack)
{
	t_stack	*be_free;

	while (*stack)
	{
		be_free = *stack;
		*stack = (*stack)->next;
		free(be_free);
	}
	*stack = NULL;
}
