# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmodrzej <dmodrzej@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 11:43:35 by dmodrzej          #+#    #+#              #
#    Updated: 2024/05/08 20:32:04 by dmodrzej         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	main.c

INC		=	-I includes -I libs/libft -I libs/ft_printf -I libs/mlx

OBJ_DIR =	objs

OBJS	=	$(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

CC		=	cc

FLAGS	=	-Wall -Wextra -Werror

# libft
LIBFT_PATH	= libs/libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# ft_printf
PRINT_F_PATH	= libs/ft_printf/
PRINT_F_NAME	= libftprintf.a
PRINT_F			= $(PRINT_F_PATH)$(PRINT_F_NAME)

# mlx
MLX_PATH	= libs/mlx/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# colors & symbols
GREEN 	= 	\033[0;32m
CYAN	=	\033[0;36m
NC		= 	\033[0m
TICK	=	✅

define PRINT_LOADING
	@printf "$(CYAN)["
	@for i in $$(seq 0 10 100); do \
		printf "▓"; \
		sleep 0.1; \
	done
	@printf "] 100%%$(RESET)\n"
endef

$(OBJ_DIR)/%.o: %.c includes/so_long.h
			@mkdir -p $(OBJ_DIR)
			@$(CC) $(FLAGS) -c $< -o $@ $(INC)

all:		$(LIBFT) $(PRINT_F) $(MLX) $(NAME)

$(NAME):	$(OBJS)
			@echo "$(CYAN)Compiling libs & program...$(NC)"
			@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINT_F) $(MLX) $(INC) -lXext -lX11 -lm
			@$(PRINT_LOADING)
			@echo "$(GREEN)Program compilation successful		$(TICK)$(NC)"

$(LIBFT):
			@make -sC $(LIBFT_PATH)

$(PRINT_F):
			@make -sC $(PRINT_F_PATH)

$(MLX):
			@make -sC $(MLX_PATH)

clean:		
			@echo "$(CYAN)Cleaning .o files...$(NC)"
			@make clean -sC $(LIBFT_PATH)
			@make clean -sC $(PRINT_F_PATH)
			@make clean -sC $(MLX_PATH)
			@rm -rf $(OBJ_DIR)
			@$(PRINT_LOADING)
			@echo "$(GREEN)Cleaning of of .o files successful	$(TICK)$(NC)"

fclean:		clean
			@echo "$(CYAN)Cleaning libs & main program...$(NC)"
			@rm -f $(NAME) $(LIBFT) $(PRINT_F) $(MLX)
			@$(PRINT_LOADING)
			@echo "$(GREEN)Full cleaning successful		$(TICK)$(NC)"

re:			fclean all

.PHONY:		all clean fclean re