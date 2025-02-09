# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 14:58:48 by bfleury           #+#    #+#              #
#    Updated: 2025/02/08 19:16:22 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap

LIB					= libftprintf.a
LIB_DIR				= lib

CC					= cc
CFLAGS				= -Wall -Wextra -Werror

SRCS_DIR			= srcs
SRCS				= push_swap.c\
					ps_move.c\
					ps_sort.c\
					ps_parse.c\
					ps_check.c\
					ps_operations.c\
					ps_calculations.c\
					ps_min_max_utils.c\
					ps_double_operations.c

OBJS_DIR			= objs
OBJS				= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all:				$(LIB) $(NAME)

$(NAME):			$(OBJS_DIR) $(OBJS)
					@${CC} ${CFLAGS} $(OBJS) -L$(LIB_DIR) -lftprintf -o $(NAME)

$(OBJS_DIR):
					@mkdir -p objs

$(OBJS_DIR)/%.o:	%.c
					@$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

$(LIB):
					@make -C $(LIB_DIR)

clean:
					@make clean -C $(LIB_DIR)
					@rm -rf $(OBJS_DIR)

fclean:				clean
					@make fclean -C $(LIB_DIR)
					@rm -f $(NAME)

re:					fclean all

.PHONY:				clean fclean re