# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 14:58:48 by bfleury           #+#    #+#              #
#    Updated: 2025/02/12 04:49:03 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################### PROJECT ###################################


NAME				= push_swap

CC					= cc
CFLAGS				= -Wall -Wextra -Werror

LIB_DIR				= lib

LIBFT				= libft.a
LIBFT_DIR			= $(LIB_DIR)/Libft

LIBPRINTF			= libftprintf.a
LIBPRINTF_DIR		= $(LIB_DIR)/Ft_Printf

FILES				= push_swap.c			\
					ps_move.c				\
					ps_sort.c				\
					ps_parse.c				\
					ps_check.c				\
					ps_operations.c			\
					ps_calculations.c		\
					ps_min_max_utils.c		\
					ps_double_operations.c

SRCS_DIR			= srcs
SRCS				= $(addprefix $(SRCS_DIR)/, $(FILES))

OBJS_DIR			= objs
OBJS				= $(FILES:%.c=$(OBJS_DIR)/%.o)


#################################### RULES ####################################


all:				$(LIBFT) $(LIBPRINTF) $(NAME)

$(NAME):			$(OBJS_DIR) $(OBJS)
					@${CC} ${CFLAGS} $(OBJS) -L$(LIBFT_DIR) -l$(LIBFT:lib%.a=%) -L$(LIBPRINTF_DIR) -l$(LIBPRINTF:lib%.a=%) -o $(NAME)

$(OBJS_DIR):
					@mkdir -p objs

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
					@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
					@make bonus -C $(LIBFT_DIR)

$(LIBPRINTF):
					@make -C $(LIBPRINTF_DIR)

clean:
					@make clean -C $(LIBFT_DIR)
					@make clean -C $(LIBPRINTF_DIR)
					@rm -rf $(OBJS_DIR)

fclean:				clean
					@make fclean -C $(LIBFT_DIR)
					@make fclean -C $(LIBPRINTF_DIR)
					@rm -f $(NAME)

re:					fclean all

.PHONY:				clean fclean re