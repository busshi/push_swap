/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:27:34 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/08 15:47:16 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	op_init(t_op **op, t_op **less)
{
	*op = (t_op *)malloc(sizeof(t_op));
	if (!*op)
		return ;
	*less = (t_op *)malloc(sizeof(t_op));
	if (!*less)
		return ;
	(*op)->a = 0;
	(*op)->b = 0;
	(*op)->a_b = 0;
	(*op)->op = 0;
	(*op)->reverse_a = 0;
	(*op)->reverse_b = 0;
	(*less)->a = 0;
	(*less)->b = 0;
	(*less)->a_b = 0;
	(*less)->op = 0;
	(*less)->reverse_a = 0;
	(*less)->reverse_b = 0;
}

void	choose_less_op(t_op *less, t_op *op)
{
	less->a = op->a;
	less->b = op->b;
	less->a_b = op->a_b;
	less->op = op->op;
	less->reverse_a = op->reverse_a;
	less->reverse_b = op->reverse_b;
}
