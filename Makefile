# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 14:58:48 by bfleury           #+#    #+#              #
#    Updated: 2025/02/15 21:36:45 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################### PROJECT ###################################


NAME				= push_swap

LIB_DIR				= lib
LIBNAME				= libftfull_bonus.a
LIBFLAGS			= -L$(LIB_DIR) -l$(LIBNAME:lib%.a=%)

CC					= cc
CFLAGS				= -Wall -Wextra -Werror

RM					= rm -rf

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


all:				$(NAME)

$(NAME):			$(LIBNAME) $(OBJS_DIR) $(OBJS)
					@${CC} ${CFLAGS} $(OBJS) $(LIBFLAGS) -o $(NAME)

$(OBJS_DIR):
					@mkdir -p objs

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
					@$(CC) $(CFLAGS) -c $< -o $@

$(LIBNAME):
					@$(MAKE) $(LIBNAME) -C $(LIB_DIR)

clean:
					@$(MAKE) clean -C $(LIB_DIR)
					@$(RM) $(OBJS_DIR)

fclean:				clean
					@$(MAKE) fclean -C $(LIB_DIR)
					@$(RM) $(NAME)

re:					fclean all

.PHONY:				clean fclean re