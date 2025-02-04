# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfleury <bfleury@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/23 00:12:15 by bfleury           #+#    #+#              #
#    Updated: 2025/01/18 19:05:41 by bfleury          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libftprintf.a
NAME_PRINTF			= libprintf.a
NAME_LIBFT			= libft.a

CC					= cc
CFLAGS				= -Wall -Wextra -Werror

OBJS_DIR			= objs
LIBFT_DIR			= libft_srcs

SRCS				= ft_printf.c \
					ft_printf_utils.c \
					ft_printf_utils_hexa.c

LIBFT_SRCS			= ft_atoi.c\
					ft_bzero.c\
					ft_calloc.c\
					ft_isalnum.c\
					ft_isalpha.c\
					ft_isascii.c\
					ft_isdigit.c\
					ft_isprint.c\
					ft_itoa.c\
					ft_memchr.c\
					ft_memcmp.c\
					ft_memcpy.c\
					ft_memmove.c\
					ft_memset.c\
					ft_lstnew.c\
					ft_lstadd_back.c\
					ft_lstadd_front.c\
					ft_lstclear.c\
					ft_lstdelone.c\
					ft_lstiter.c\
					ft_lstlast.c\
					ft_lstmap.c\
					ft_lstsize.c\
					ft_putendl_fd.c\
					ft_putchar_fd.c\
					ft_putnbr_fd.c\
					ft_putstr_fd.c\
					ft_split.c\
					ft_strchr.c\
					ft_strdup.c\
					ft_striteri.c\
					ft_strjoin.c\
					ft_strlcat.c\
					ft_strlcpy.c\
					ft_strlen.c\
					ft_strmapi.c\
					ft_strncmp.c\
					ft_strnstr.c\
					ft_strrchr.c\
					ft_strtrim.c\
					ft_substr.c\
					ft_tolower.c\
					ft_toupper.c

OBJS				= $(SRCS:%.c=$(OBJS_DIR)/%.o) 
LIBFT_OBJS			= $(LIBFT_SRCS:%.c=$(OBJS_DIR)/%.o)

all:				$(NAME)

$(NAME):			$(OBJS_DIR) $(OBJS) $(LIBFT_OBJS)
					@ar rc $(NAME) $(OBJS) $(LIBFT_OBJS)
					@ranlib $(NAME)

$(NAME_PRINTF):		$(OBJS_DIR) $(OBJS)
					@ar rc $(NAME_PRINTF) $(OBJS)
					@ranlib $(NAME_PRINTF)

$(NAME_LIBFT):		$(OBJS_DIR) $(LIBFT_OBJS)
					@ar rc $(NAME_LIBFT) $(LIBFT_OBJS)
					@ranlib $(NAME_LIBFT)

$(OBJS_DIR):
					@mkdir -p objs

$(OBJS_DIR)/%.o:	%.c
					@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/%.o:	$(LIBFT_DIR)/%.c
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@rm -rf objs

fclean:				clean
					@rm -f $(NAME) $(NAME_PRINTF) $(NAME_LIBFT)

re:					fclean all

.PHONY:				clean fclean re
