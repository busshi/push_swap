/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 21:28:12 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/07 19:07:22 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		exec_cmd(char *cmd, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(cmd, "sa"))
		swap(a, 'a', FALSE);
	else if (!ft_strcmp(cmd, "sb"))
		swap(b, 'b', FALSE);
	else if (!ft_strcmp(cmd, "ss"))
		swap_both(a, b, FALSE);
	else if (!ft_strcmp(cmd, "pa"))
		push(b, a, 'a', FALSE);
	else if (!ft_strcmp(cmd, "pb"))
		push(a, b, 'b', FALSE);
	else if (!ft_strcmp(cmd, "ra"))
		rotate(a, 'a', FALSE);
	else if (!ft_strcmp(cmd, "rb"))
		rotate(b, 'b', FALSE);
	else if (!ft_strcmp(cmd, "rr"))
		rotate_both(a, b, FALSE);
	else if (!ft_strcmp(cmd, "rra"))
		reverse_rotate(a, 'a', FALSE);
	else if (!ft_strcmp(cmd, "rrb"))
		reverse_rotate(b, 'b', FALSE);
	else if (!ft_strcmp(cmd, "rrr"))
		reverse_rotate_both(a, b, FALSE);
}
