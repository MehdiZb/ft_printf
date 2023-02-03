# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Mzblah <mehdi.zblah@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 14:40:05 by Mzblah            #+#    #+#              #
#    Updated: 2019/12/05 17:12:45 by mzblah           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_SRC = libft

LIBFT = ./$(LIBFT_SRC)/libft.a

PATH_SRC = ./srcs/

PATH_SRC_CONV = ./conversions/

HEADER = ./include

CFLAGS = -Wall -Wextra -Werror

OPTION = -c -I $(HEADER)

SRCS = 	$(PATH_SRC)ft_printf.c 				\
		$(PATH_SRC)ft_printf_utils.c 		\
		$(PATH_SRC)ft_write_format.c 		\
		$(PATH_SRC)ft_parse_conv.c	 		\
		$(PATH_SRC_CONV)ft_flags.c 			\
		$(PATH_SRC_CONV)ft_conv_c_percent.c	\
		$(PATH_SRC_CONV)ft_conv_s.c			\
		$(PATH_SRC_CONV)ft_conv_p.c			\
		$(PATH_SRC_CONV)ft_conv_number.c

BONUS =	$(PATH_SRC_CONV)ft_conv_n_bonus.c

OBJS = $(SRCS:.c=.o)

BONUS_OBJS = $(BONUS:.c=.o)

.c.o:
	cc $(CFLAGS) -c $< -o $@ -I $(HEADER)

all:	$(NAME)

$(NAME): $(OBJS) $(BONUS:.c=.o)
	make -C $(LIBFT_SRC)
	cp $(LIBFT) ./$(NAME)
	ar rc $(NAME) $(OBJS) $(BONUS:.c=.o)
	ranlib $(NAME)

bonus : $(NAME) $(BONUS_OBJS)
	ar rc $(NAME) $(BONUS_OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS) $(BONUS_OBJS)
fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
