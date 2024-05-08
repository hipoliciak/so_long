# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/10 16:37:47 by dmodrzej          #+#    #+#              #
#    Updated: 2024/05/08 18:13:27 by dmodrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_putchar.c ft_putnbr.c ft_putpointer.c \
			ft_putunsigned.c ft_putnbrhex.c ft_putstr.c

OBJ_DIR =	obj

OBJS	=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CC		=	cc

FLAGS	=	-Wall -Wextra -Werror

$(OBJ_DIR)/%.o: %.c
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(FLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

clean:
			@rm -rf $(OBJ_DIR)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
