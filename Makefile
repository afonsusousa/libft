# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amagno-r <amagno-r@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/03 16:47:35 by amagno-r          #+#    #+#              #
#    Updated: 2025/04/12 19:45:08 by amagno-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = 	srcs/ft_atoi.c \
	srcs/ft_bzero.c \
	srcs/ft_calloc.c \
	srcs/ft_isalnum.c \
	srcs/ft_isalpha.c \
	srcs/ft_isascii.c \
	srcs/ft_isdigit.c \
	srcs/ft_isprint.c \
	srcs/ft_itoa.c \
	srcs/ft_memchr.c \
	srcs/ft_memcmp.c \
	srcs/ft_memcpy.c \
	srcs/ft_memmove.c \
	srcs/ft_memset.c \
	srcs/ft_putchar_fd.c \
	srcs/ft_putendl_fd.c \
	srcs/ft_putnbr_fd.c \
	srcs/ft_putstr_fd.c \
	srcs/ft_split.c \
	srcs/ft_strchr.c \
	srcs/ft_strdup.c \
	srcs/ft_striteri.c \
	srcs/ft_strjoin.c \
	srcs/ft_strlcat.c \
	srcs/ft_strlcpy.c \
	srcs/ft_strlen.c \
	srcs/ft_strmapi.c \
	srcs/ft_strncmp.c \
	srcs/ft_strnstr.c \
	srcs/ft_strrchr.c \
	srcs/ft_strtrim.c \
	srcs/ft_substr.c \
	srcs/ft_tolower.c \
	srcs/ft_toupper.c 

BONUS = bonus/ft_lstadd_back.c \
	bonus/ft_lstadd_front.c \
	bonus/ft_lstclear.c \
	bonus/ft_lstdelone.c \
	bonus/ft_lstiter.c \
	bonus/ft_lstlast.c \
	bonus/ft_lstmap.c \
	bonus/ft_lstnew.c \
	bonus/ft_lstsize.c

OBJS = $(SRCS:.c=.o)

OBJSBONUS = $(BONUS:.c=.o)

HEADERS = includes

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: $(OBJS) $(OBJSBONUS)
	ar rcs $(NAME) $(OBJS) $(OBJSBONUS)

%.o: %.c
	$(CC) $(CFLAGS) -I$(HEADERS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJSBONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

so: $(OBJS) $(OBJSBONUS)
	$(CC) -nostartfiles -fPIC -I$(HEADERS) $(CFLAGS) $(SRCS) $(BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(OBJSBONUS)
