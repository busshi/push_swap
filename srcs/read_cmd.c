/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:38:35 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/12 17:01:16 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	run_cmd(t_list *rules, t_stack **a, t_stack **b, int flag_exit)
{
	if (!flag_exit)
	{
		while (rules)
		{
			exec_cmd((char *)rules->content, a, b);
			rules = rules->next;
		}
	}
	if (check_sort(a, b) && !flag_exit)
		ft_putstr("OK\n");
	else if (!check_sort(a, b) && !flag_exit)
		ft_putstr("KO\n");
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

static int	break_or_continue(char *cmd)
{
	if (!check_cmd(cmd))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}

void		read_cmd(t_stack **a, t_stack **b)
{
	char	*cmd;
	t_list	*rules;
	int		gnl;
	int		flag_exit;

	gnl = 1;
	flag_exit = 0;
	rules = NULL;
	while (gnl >= 0)
	{
		gnl = ft_gnl_clear(0, &cmd, flag_exit);
		if (!gnl)
		{
			if (!flag_exit)
				free(cmd);
			break ;
		}
		flag_exit = break_or_continue(cmd);
		add_cmd(&rules, cmd);
		free(cmd);
	}
	run_cmd(rules, a, b, flag_exit);
	ft_lstclear(&rules, &ft_lstfree_content);
}
