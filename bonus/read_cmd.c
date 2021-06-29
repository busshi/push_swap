/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:38:35 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/12 19:59:11 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static void	run_cmd(t_list *rules, t_stack **a, t_stack **b, t_option *option)
{
	if (!option->exit)
	{
		while (rules)
		{
			exec_cmd((char *)rules->content, a, b, option);
			rules = rules->next;
		}
	}
	if (check_sort(a, b, option) && !option->exit)
	{
		if (option->color)
			ft_putstr("\033[0;32mOK\n\033[0;m");
		else
			ft_putstr("OK\n");
	}
	else if (!check_sort(a, b, option) && !option->exit)
	{
		if (option->color)
			ft_putstr("\033[0;31mKO\n\033[0;m");
		else
			ft_putstr("KO\n");
	}
}

static void	add_cmd(t_list **rules, char *cmd)
{
	t_list	*new;
	char	*s;

	s = NULL;
	if (cmd)
		s = ft_strdup(cmd);
	new = ft_lstnew(s);
	if (!new)
		return ;
	ft_lstadd_back(rules, new);
}

static int	check_cmd(char *s)
{
	if (!ft_strcmp(s, "sa") || !ft_strcmp(s, "sb") || !ft_strcmp(s, "ss") ||
			!ft_strcmp(s, "ra") || !ft_strcmp(s, "rb") || !ft_strcmp(s, "rr") ||
			!ft_strcmp(s, "rra") || !ft_strcmp(s, "rrb") ||
			!ft_strcmp(s, "rrr") || !ft_strcmp(s, "pa") || !ft_strcmp(s, "pb"))
		return (1);
	return (0);
}

static int	break_or_continue(char *cmd, t_option *option)
{
	if (!check_cmd(cmd))
	{
		if (option->color)
			ft_putstr_fd("\033[0;31mError\n\033[0;m", 2);
		else
			ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

void		read_cmd(t_stack **a, t_stack **b, t_option *option)
{
	char	*cmd;
	t_list	*rules;
	int		gnl;

	gnl = 1;
	rules = NULL;
	while (gnl >= 0)
	{
		gnl = ft_gnl_clear(0, &cmd, option->exit);
		if (!gnl)
		{
			if (!option->exit)
				free(cmd);
			break ;
		}
		option->exit = break_or_continue(cmd, option);
		add_cmd(&rules, cmd);
		free(cmd);
	}
	run_cmd(rules, a, b, option);
	ft_lstclear(&rules, &ft_lstfree_content);
}
