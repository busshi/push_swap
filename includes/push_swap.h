/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:03:44 by aldubar           #+#    #+#             */
/*   Updated: 2021/04/08 15:38:37 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef enum		e_value
{
	MIN,
	MAX
}					t_value;

typedef enum		e_bol
{
	TRUE,
	FALSE
}					t_bol;

typedef struct		s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_op
{
	int		a;
	int		b;
	int		a_b;
	int		op;
	short	reverse_a;
	short	reverse_b;
}					t_op;

char				**create_tab(char **av);
int					check_input(char **tab);
int					create_stack(char **tab, t_stack **a);
size_t				stack_size(t_stack *stack);
t_stack				*new_elem(int nb);
void				add_stack_front(t_stack **stack, t_stack *new);
void				read_cmd(t_stack **a, t_stack **b);
void				exec_cmd(char *cmd, t_stack **a, t_stack **b);
void				swap(t_stack **stack, char c, enum e_bol display);
void				swap_both(t_stack **a, t_stack **b, enum e_bol display);
void				push(t_stack **src, t_stack **dest, char c,
		enum e_bol display);
void				rotate(t_stack **stack, char c, enum e_bol display);
void				rotate_both(t_stack **a, t_stack **b, enum e_bol display);
void				reverse_rotate(t_stack **stack, char c, enum e_bol display);
void				reverse_rotate_both(t_stack **a, t_stack **b,
		enum e_bol display);
void				sort_stack(t_stack **a, t_stack **b);
void				op_init(t_op **op, t_op **less);
t_op				*calculate_less_op(t_stack **a, t_stack **b);
void				choose_less_op(t_op *less, t_op *op);
void				exec_op(t_op *op, t_stack **a, t_stack **b);
void				push_and_pop(t_stack **a, t_stack **b);
int					find_last(t_stack *stack);
int					find_min(t_stack *stack);
int					find_max(t_stack *stack);
size_t				find_pos(t_stack *stack, enum e_value value);
int					check_sort(t_stack **a, t_stack **b);
void				free_tab_fail(char **tab, int max);
void				delone_stack(t_stack **stack);
void				free_stack(t_stack **stack);

#endif
