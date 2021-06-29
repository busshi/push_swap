/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 20:26:29 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/12 21:45:20 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	print_line(int nb, t_stack *stack, char pile, t_option *option)
{
	int		last;
	int		next;

	next = option->next;
	last = find_last(stack);
	if (option->color)
	{
		if ((nb < next && pile == 'a' && !option->reverse && nb != last) ||
				(nb > next && pile == 'a' && option->reverse && nb != last) ||
				(nb < next && pile == 'b' && !option->reverse && nb != last) ||
				(nb > next && pile == 'b' && option->reverse && nb != last) ||
				(nb > next && pile == 'a' && !option->reverse && nb == last) ||
				(nb < next && pile == 'a' && option->reverse && nb == last))
			ft_putstr("\033[0;32m*\033[0;m");
		else
			ft_putstr("\033[0;31m*\033[0;m");
	}
	else
		ft_putchar('*');
}

static void	print_lines(int nb, t_stack *stack, char pile, t_option *option)
{
	int		i;
	int		stop;

	i = 0;
	ft_putstr("\033[20G");
	if (pile == 'b')
		ft_putstr("\033[80G");
	if (option->max - option->min == 0)
		stop = 35;
	else
		stop = 35 * (nb - option->min) / (option->max - option->min);
	while (i <= stop)
	{
		print_line(nb, stack, pile, option);
		i++;
	}
}

static void	display_stack(t_stack *stack, char pile, t_option *option)
{
	if (pile == 'a')
	{
		option->min = option->min_a;
		option->max = option->max_a;
		ft_putstr("\033[5G");
	}
	else if (pile == 'b')
	{
		option->min = option->min_b;
		option->max = option->max_b;
		ft_putstr("\033[65G");
	}
	ft_putnbr(stack->nb);
	if (stack->next)
	{
		option->next = stack->next->nb;
		option->current = stack->nb;
	}
	else
		option->next = option->current;
	print_lines(stack->nb, stack, pile, option);
}

static void	init_display(t_stack *a, t_stack *b, t_option *option)
{
	if (a)
	{
		option->min_a = find_min(a);
		option->max_a = find_max(a);
	}
	if (b)
	{
		option->min_b = find_min(b);
		option->max_b = find_max(b);
	}
}

void		display(char *cmd, t_stack *a, t_stack *b, t_option *option)
{
	init_display(a, b, option);
	system("clear");
	if (option->color)
		ft_putstr("\033[1;34m");
	ft_putstr(cmd);
	if (option->color)
		ft_putstr("\033[0;m");
	while (a || b)
	{
		if (a && b)
		{
			display_stack(a, 'a', option);
			display_stack(b, 'b', option);
		}
		else if (a && !b)
			display_stack(a, 'a', option);
		else if (!a && b)
			display_stack(b, 'b', option);
		ft_putchar('\n');
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
	ft_putstr("\033[5G_\033[65G_\n\033[5Ga\033[65Gb\n\n");
}
