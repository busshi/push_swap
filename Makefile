# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 10:19:00 by aldubar           #+#    #+#              #
#    Updated: 2021/07/03 12:11:10 by aldubar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap

CHECKER			=	checker

SRCS			=	push_swap.c \
				parse.c \
				swap_push.c \
				rotate.c \
				reverse_rotate.c \
				sort.c \
				calc_op.c \
				exec_op.c \
				check_sort.c \
				sort_utils.c \
				calc_utils.c \
				stack_utils.c \
				free_utils.c

SRCS_CHECKER		=	checker.c \
				parse.c \
				read_cmd.c \
				exec_cmd.c \
				swap_push.c \
				rotate.c \
				reverse_rotate.c \
				check_sort.c \
				sort_utils.c \
				stack_utils.c \
				free_utils.c

SRCS_OPTION		=	option.c \
				display.c

CC			=	@clang

CFLAGS			=	-Wall -Wextra -Werror -O3

RM			=	@rm -rf

INC_DIR			=	./includes
LIB_DIR			=	./libft

OBJS			=	$(addprefix srcs/, $(SRCS:.c=.o))

OBJS_CHECKER		=	$(addprefix srcs/, $(SRCS_CHECKER:.c=.o))

OBJS_BONUS		=	$(addprefix bonus/, $(SRCS:.c=.o))

OBJS_CHECKER_BONUS	=	$(addprefix bonus/, $(SRCS_CHECKER:.c=.o))

OBJS_OPTION		=	$(addprefix bonus/, $(SRCS_OPTION:.c=.o))

OK			=	"\r[ \033[0;32mok\033[0m ]"


.c.o:
		$(CC) $(CFLAGS) -I includes -I libft -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(OBJS_CHECKER) $(INC_DIR)/push_swap.h
		@make -s -C $(LIB_DIR)
		@echo "[....] Compiling push_swap and checker\c"
		$(CC) $(CFLAGS) $(OBJS) -L$(LIB_DIR) -lft -o $@
		$(CC) $(CFLAGS) $(OBJS_CHECKER) -L$(LIB_DIR) -lft -o $(CHECKER)
		@echo $(OK)

all:		$(NAME)

bonus:		$(OBJS_BONUS) $(OBJS_CHECKER_BONUS) $(OBJS_OPTION) $(INC_DIR)/push_swap_bonus.h
		@make -s -C $(LIB_DIR)
		@echo "[....] Compiling bonus for push_swap and checker\c"
		$(CC) $(CFLAGS) $(OBJS_BONUS) $(OBJS_OPTION) -L$(LIB_DIR) -lft -o $(NAME)
		$(CC) $(CFLAGS) $(OBJS_CHECKER_BONUS) $(OBJS_OPTION) -L$(LIB_DIR) -lft -o $(CHECKER)
		@echo $(OK)
clean:
		@make clean -s -C $(LIB_DIR)
		@echo "[....] Removing push_swap and checker objects\c"
		$(RM) $(OBJS) $(OBJS_CHECKER) $(OBJS_BONUS) $(OBJS_CHECKER_BONUS) $(OBJS_OPTION)
		@echo $(OK)

fclean:		clean
		@echo "[....] Removing libft.a\c"
		$(RM) libft/libft.a
		@echo $(OK)
		$(RM) $(NAME) $(CHECKER)
		@echo "[....] Removing $(NAME) and $(CHECKER)\c"
		$(RM) $(NAME) $(CHECKER)
		@echo $(OK)

re:		fclean all

check:		fclean
		@if [ ! -d push_swap_checker ]; then git clone https://github.com/busshi/push_swap_checker.git; fi
		@cd push_swap_checker && /bin/bash grademe.sh fast

.PHONY:		all clean fclean re bonus check
