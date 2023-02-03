# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Mzblah <mehdi.zblah@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 14:40:05 by Mzblah            #+#    #+#              #
#    Updated: 2019/11/16 14:21:52 by mzblah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

BONUS = bonusse

PATH_SRC = ./

HEADER = ./

CFLAGS = -Wall -Wextra -Werror

OPTION = -c -I $(HEADER)

SRCS =	$(PATH_SRC)ft_putchar.c 	\
		$(PATH_SRC)ft_putstr.c		\
		$(PATH_SRC)ft_putnbr.c		\
		$(PATH_SRC)ft_isalpha.c		\
		$(PATH_SRC)ft_isdigit.c		\
		$(PATH_SRC)ft_isalnum.c		\
		$(PATH_SRC)ft_isascii.c		\
		$(PATH_SRC)ft_isprint.c		\
		$(PATH_SRC)ft_isspace.c		\
		$(PATH_SRC)ft_toupper.c		\
		$(PATH_SRC)ft_tolower.c		\
		$(PATH_SRC)ft_bzero.c		\
		$(PATH_SRC)ft_strnew.c		\
		$(PATH_SRC)ft_strlen.c		\
		$(PATH_SRC)ft_strdup.c		\
		$(PATH_SRC)ft_strcpy.c		\
		$(PATH_SRC)ft_strncpy.c		\
		$(PATH_SRC)ft_strcat.c		\
		$(PATH_SRC)ft_strncat.c		\
		$(PATH_SRC)ft_strchr.c		\
		$(PATH_SRC)ft_strrchr.c		\
		$(PATH_SRC)ft_strcmp.c		\
		$(PATH_SRC)ft_strncmp.c		\
		$(PATH_SRC)ft_strstr.c		\
		$(PATH_SRC)ft_strnstr.c		\
		$(PATH_SRC)ft_strlcat.c		\
		$(PATH_SRC)ft_strlcpy.c		\
		$(PATH_SRC)ft_atoi.c		\
		$(PATH_SRC)ft_memset.c		\
		$(PATH_SRC)ft_memmove.c		\
		$(PATH_SRC)ft_memcpy.c		\
		$(PATH_SRC)ft_memccpy.c		\
		$(PATH_SRC)ft_memchr.c		\
		$(PATH_SRC)ft_memcmp.c		\
		$(PATH_SRC)ft_strdup.c		\
		$(PATH_SRC)ft_substr.c		\
		$(PATH_SRC)ft_strjoin.c		\
		$(PATH_SRC)ft_strtrim.c		\
		$(PATH_SRC)ft_split.c		\
		$(PATH_SRC)ft_itoa.c		\
		$(PATH_SRC)ft_strmapi.c		\
		$(PATH_SRC)ft_putchar_fd.c	\
		$(PATH_SRC)ft_putstr_fd.c	\
		$(PATH_SRC)ft_putendl_fd.c	\
		$(PATH_SRC)ft_putnbr_fd.c	\
		$(PATH_SRC)ft_calloc.c		\
		$(PATH_SRC)ft_is_char_in_str.c	

OBJS = $(SRCS:.c=.o)

BONUS_SRCS =	ft_lstnew_bonus.c		\
				ft_lstlast_bonus.c		\
				ft_lstadd_front_bonus.c	\
				ft_lstadd_back_bonus.c	\
				ft_lstdelone_bonus.c	\
				ft_lstclear_bonus.c		\
				ft_lstiter_bonus.c		\
				ft_lstmap_bonus.c		\
				ft_lstsize_bonus.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

.c.o:
	cc $(CFLAGS) -c $< -o $@ -I $(HEADER)

all:	$(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(OBJS) $(BONUS_OBJS)
	ar rc $(NAME) $(OBJS) $(BONUS_OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS) $(BONUS_OBJS)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
