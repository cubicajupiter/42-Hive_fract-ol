# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/22 10:34:09 by jvalkama          #+#    #+#              #
#    Updated: 2025/05/04 14:51:55 by jvalkama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANDATORY		= ft_isalnum.c ft_itoa.c ft_memset.c ft_split.c ft_strlcat.c\
ft_strnstr.c ft_toupper.c ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c\
ft_strlcpy.c ft_strrchr.c ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c\
ft_strdup.c ft_strlen.c ft_strtrim.c ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c\
ft_striteri.c ft_strmapi.c ft_substr.c ft_calloc.c ft_isprint.c ft_memmove.c\
ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c\

BONUS			= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c\
ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c\
ft_lstiter_bonus.c ft_lstmap_bonus.c\

OBJS			= $(MANDATORY:%.c=%.o)

BONUS_OBJS		= $(BONUS:%.c=%.o)

HEADER			= libft.h

CC				= cc

CFLAGS			= -Wall -Wextra -Werror -g

RM				= rm -f

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
					@echo "Creating library $(NAME)"
					ar -rcs $(NAME) $(OBJS)

bonus:			$(NAME) $(BONUS_OBJS)
					@echo "Adding bonus functions into library $(NAME)"
					ar -rcs $(NAME) $(BONUS_OBJS)

%.o:			%.c $(HEADER)
					@echo "Compiling $<"
					$(CC) $(CFLAGS) -c $< -o $@

clean:
					@echo "Cleaning object files"
					@$(RM) $(OBJS)
					@$(RM) $(BONUS_OBJS)

fclean:			clean
					@echo "Cleaning library"
					@$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re bonus
